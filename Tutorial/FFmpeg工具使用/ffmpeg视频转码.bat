@ECHO OFF
REM FF Prompt 1.2
REM Open a command prompt to run ffmpeg/ffplay/ffprobe
REM Copyright (C) 2013-2015  Kyle Schwarz

TITLE FFMpeg

IF NOT EXIST bin\ffmpeg.exe (
  CLS
  ECHO bin\ffmpeg.exe could not be found.
  GOTO:error
)

CD bin || GOTO:error

REM ��װ��ʽת����ʹ��Ĭ�ϱ����ʽ
REM ffmpeg -i ../video/IMG_0886.MOV ../video/output_mpeg4_mp3.avi 

REM ��װ��ʽת�������������ʽ
REM ffmpeg -i ../video/IMG_0886.MOV -c copy ../video/output_copy.avi 

REM ��Ƶת��
REM ffmpeg -i ../video/IMG_0886.MOV -c:v mjpeg  ../video/output_mjpeg.avi 

@REM ��ȡ��Ƶ��
@REM ffmpeg -i ../video/IMG_0886.MOV -c:v copy -an ../video/IMG_0886_v.MOV

@REM ��ȡ��Ƶ��
@REM ffmpeg -i ../video/IMG_0886.MOV -c:a copy -vn ../video/IMG_0886_a.aac

@REM ��Ƶ��ȡ
@REM ffmpeg -ss 5 -t 5 -i ../video/IMG_0886.MOV -c copy ../video/IMG_0886_cut.MOV

:error
ECHO.
ECHO Press any key to exit.
PAUSE >nul
GOTO:EOF