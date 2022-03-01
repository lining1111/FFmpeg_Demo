//
// Created by lining on 3/1/22.
//

#include <iostream>
#include <libavformat/avformat.h>

using namespace std;

static void usage(const char *program_name) {
    cout << "usage: " << string(program_name) << " input_dir" << endl;
    cout << "API example program to show how to list files in directory accessed through AVIOContext." << endl;
}

static int list_op(const char *input_dir){
    AVIODirEntry *entry = nullptr;
    AVIODirContext *ctx = nullptr;
    int cnt,ret;

}

int main(int argc, char **argv) {
    int ret;
    av_log_set_level(AV_LOG_DEBUG);//设置日志级别为debug
    if (argc > 2) {
        //输出帮助信息
        usage(argv[0]);
        return 1;
    }
    avformat_network_init();
    ret = list_op(argv[1]);
    avformat_network_deinit();
    return ret < 0 ? 1 : 0;
}
