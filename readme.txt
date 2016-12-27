1. ILedSevice.aidl
   frameworks/base/core/java/android/os/
2. 修改frameworks/base/Android.mk
	 + core/java/android/os/ILedService.aidl /
3.  mmm frameworks/base
	生成out/target/common/obj/JAVA_LIBRARIES/framework_intermediates/src/core/java/android/ILedSevice.java

4. LedSevice.java
	frameworks/base/services/core/java/com/android/server
5.	frameworks/base/services/core/Android.mk 无需修改
