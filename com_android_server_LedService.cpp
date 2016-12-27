#define LOG_TAG "LedService"

#include "jni.h"
#include "JNIHelp.h"

#include <utils/misc.h>
#include <utils/Log.h>
#include <stdio.h>

namespace android
{

static int fd = 0;

jint c_ledOpen(JNIEnv *env, jobject cls)
{
ALOGI(  "LedService:c_ledOpen\n");
	fd = open("/dev/leds",O_RDWR);
	if( fd > 0 )
		return 1;
	else 
		return 0;

}

void c_ledClose(JNIEnv *env, jobject cls)
{
	close( fd );
	ALOGI(  "LedService:c_ledClose\n");
}

jint c_ledCtl(JNIEnv *env, jobject cls,jint which, jint status)
{
	int ret = 0;
	ret = ioctl( fd, status, which );
	ALOGI(  "LedService:c_ledCtl  %d %d\ n",which,  status);
	return 0;
}

static JNINativeMethod method_table[] = {
  	{"ledOpen", "()I", (void *)c_ledOpen},
	{"ledClose", "()V", (void *)c_ledClose},
	{"ledCtl", "(II)I", (void *)c_ledCtl},
};

int register_android_server_VibratorService(JNIEnv *env)
{
    return jniRegisterNativeMethods(env, "com/android/server/LedService",
            method_table, NELEM(method_table));
}

};