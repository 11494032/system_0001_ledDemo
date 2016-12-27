1. ILedSevice.aidl
   frameworks/base/core/java/android/os/
2. 修改frameworks/base/Android.mk
	 + core/java/android/os/ILedService.aidl /
3.  mmm frameworks/base
	生成out/target/common/obj/JAVA_LIBRARIES/framework_intermediates/src/core/java/android/ILedSevice.java

4. LedSevice.java
	frameworks/base/services/core/java/com/android/server
5. frameworks/base/services/core/Android.mk 无需修改

6. SystemServer.java (frameworks/base/services/java/com/android/server)
	+	Slog.i(TAG, "Led Service");
        ServiceManager.addService("led", new LedService() );
		
7. com_android_server_LedService.cpp (frameworks/base/services/core/jni)

8. Android.mk (frameworks/base/services/core/jni)
	$(LOCAL_REL_DIR)/com_android_server_LedService.cpp /
9. 	Onload.cpp (frameworks/base/services/core/jni)
	+	register_android_server_LedService(env);