
package com.android.server;

import android.os.ILedService;

public class LedService extends ILedService.Stub
{
        
    private static final String TAG = "LedService";
	
	public int LedCtl(int which, int status) throws android.os.RemoteException
	{
		native_LedCtl( which, status);
	}
	
	public native int ledOpen();
	
	public native int LedCtl(int which, int status);
	
	public native void ledClose();
}