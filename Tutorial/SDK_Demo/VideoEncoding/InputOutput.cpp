#include <string.h>
#include <stdlib.h>
#include "InputOutput.h"

bool Parse_input_param(int argc, char **argv, IOParam &io_param) {
    bool bNameInFound = false, bNameOutFound = false, bWidthFound = false, bHeightFound = false, bBitrateFound = false, bTotalFrames = false;

    io_param.nFrameRate = 25;
    io_param.nGOPSize = 10;
    io_param.nMaxBFrames = 1;

    //根据命令行解析输入参数
    for (int idx = 1; idx < argc; idx++) {
        if (!strcmp(argv[idx], "-i")) {
            io_param.pNameIn = argv[idx + 1];
            bNameInFound = true;
        } else if (!strcmp(argv[idx], "-o")) {
            io_param.pNameOut = argv[idx + 1];
            bNameOutFound = true;
        } else if (!strcmp(argv[idx], "-w")) {
            io_param.nImageWidth = atoi(argv[idx + 1]);
            bWidthFound = true;
        } else if (!strcmp(argv[idx], "-h")) {
            io_param.nImageHeight = atoi(argv[idx + 1]);
            bHeightFound = true;
        } else if (!strcmp(argv[idx], "-br")) {
            io_param.nBitRate = atol(argv[idx + 1]);
            bBitrateFound = true;
        } else if (!strcmp(argv[idx], "-tf")) {
            io_param.nTotalFrames = atoi(argv[idx + 1]);
            bTotalFrames = true;
        } else if (!strcmp(argv[idx], "-fr")) {
            io_param.nFrameRate = atoi(argv[idx + 1]);
        } else if (!strcmp(argv[idx], "-gs")) {
            io_param.nGOPSize = atoi(argv[idx + 1]);
        } else if (!strcmp(argv[idx], "-mbs")) {
            io_param.nMaxBFrames = atoi(argv[idx + 1]);
        }
    } //for (int idx = 1; idx < argc; idx++)

    //必要信息缺失，返回错误
    if (!bNameInFound) {
        printf("Error: Cannot find input file name.\n");
        return false;
    }
    if (!bNameOutFound) {
        printf("Error: Cannot find output file name.\n");
        return false;
    }
    if (!bWidthFound) {
        printf("Error: Cannot find image width.\n");
        return false;
    }
    if (!bHeightFound) {
        printf("Error: Cannot find image height.\n");
        return false;
    }
    if (!bBitrateFound) {
        printf("Error: Cannot find bitrate.\n");
        return false;
    }

    printf("Paramaters parsing OK!\n");
    return true;
}

bool Open_file(IOParam &io_param) {
    //打开输入文件
    io_param.pFin = fopen(io_param.pNameIn, "rb");
    if (!(io_param.pFin)) {
        fprintf(stderr, "Could not open %s\n", io_param.pNameIn);
        return false;
    }

    //打开输出文件
    io_param.pFout = fopen(io_param.pNameOut, "wb");
    if (!(io_param.pFin)) {
        fprintf(stderr, "Could not open %s\n", io_param.pNameOut);
        return false;
    }

    return true;
}

void Close_file(IOParam &io_param) {
    fclose(io_param.pFin);
    fclose(io_param.pFout);
}

int Read_yuv_data(CodecCtx &ctx, IOParam &io_param, int color_plane) {
    int frame_height = color_plane == 0 ? ctx.frame->height : ctx.frame->height / 2;
    int frame_width = color_plane == 0 ? ctx.frame->width : ctx.frame->width / 2;
    int frame_size = frame_width * frame_height;
    int frame_stride = ctx.frame->linesize[color_plane];

    if (frame_width == frame_stride) {
        //宽度和跨度相等，像素信息连续存放
        fread(ctx.frame->data[color_plane], 1, frame_size, io_param.pFin);
    } else {
        //宽度小于跨度，像素信息保存空间之间存在间隔
        for (int row_idx = 0; row_idx < frame_height; row_idx++) {
            fread(ctx.frame->data[color_plane] + row_idx * frame_stride, 1, frame_width, io_param.pFin);
        }
    }

    return frame_size;
}
