package com.secrethq.ads;

import java.lang.ref.WeakReference;

import org.cocos2dx.lib.Cocos2dxActivity;

import android.util.Log;
import android.view.View;
import android.widget.FrameLayout;
import android.widget.LinearLayout;
import android.widget.RelativeLayout;

import com.google.android.gms.ads.*;

public class PTAdAdMobBridge {
	private static final String TAG = "PTAdAdMobBridge";
	private static Cocos2dxActivity activity;
	private static WeakReference<Cocos2dxActivity> s_activity;
	private static AdView adView;
	private static InterstitialAd interstitial;
	private static LinearLayout layout;
	
	private static native String bannerId();
	private static native String interstitialId();
	private static native void interstitialDidFail();
    private static native void bannerDidFail();
    
    private static boolean isBannerScheduledForShow = false;
    private static boolean isInterstitialScheduledForShow = false;
	
	public static void initBridge(Cocos2dxActivity activity){
		Log.v(TAG, "PTAdAdMobBridge  -- INIT");
		
		
		PTAdAdMobBridge.s_activity = new WeakReference<Cocos2dxActivity>(activity);	
		PTAdAdMobBridge.activity = activity;
	
        MobileAds.initialize(PTAdAdMobBridge.activity, PTAdAdMobBridge.bannerId());

    	PTAdAdMobBridge.initBanner();
    	PTAdAdMobBridge.initInterstitial();
    	
	}

	public static void initBanner(){
		Log.v(TAG, "PTAdAdMobBridge  -- initBanner");
		PTAdAdMobBridge.s_activity.get().runOnUiThread( new Runnable() {
            public void run() {

            	if(PTAdAdMobBridge.adView != null){
            		return;
            	}
            	
        		FrameLayout frameLayout = (FrameLayout)PTAdAdMobBridge.activity.findViewById(android.R.id.content);
        		RelativeLayout layout = new RelativeLayout( PTAdAdMobBridge.activity );
        		frameLayout.addView( layout );
        		
        		RelativeLayout.LayoutParams adViewParams = new RelativeLayout.LayoutParams(
        				AdView.LayoutParams.WRAP_CONTENT,
        				AdView.LayoutParams.WRAP_CONTENT);
        		adViewParams.addRule(RelativeLayout.ALIGN_PARENT_BOTTOM);
        		adViewParams.addRule(RelativeLayout.CENTER_IN_PARENT, RelativeLayout.TRUE);

        		PTAdAdMobBridge.adView = new AdView( PTAdAdMobBridge.activity );
        		PTAdAdMobBridge.adView.setAdSize(AdSize.SMART_BANNER);
        		PTAdAdMobBridge.adView.setAdUnitId( PTAdAdMobBridge.bannerId() );
        		
        		layout.addView(PTAdAdMobBridge.adView, adViewParams);
        		PTAdAdMobBridge.adView.setVisibility( View.INVISIBLE );

        		AdRequest adRequest = getAdRequest();
        		PTAdAdMobBridge.adView.loadAd( adRequest );		
            }
        });
	
	}
	
	public static boolean isBannerVisible(){
		if(PTAdAdMobBridge.adView == null){
			return false;
		}
		else{
			if(PTAdAdMobBridge.adView.getVisibility() == View.VISIBLE){
				return true;
			}
			else{
				return false;
			}
		}
	}
	
	public static void initInterstitial(){
		Log.v(TAG, "PTAdAdMobBridge  -- initInterstitial");
		PTAdAdMobBridge.s_activity.get().runOnUiThread( new Runnable() {
            public void run() {

            	if(PTAdAdMobBridge.interstitial != null){
            		return;
            	}
            	
				AdRequest adRequest = getAdRequest();
				
				PTAdAdMobBridge.interstitial = new InterstitialAd( PTAdAdMobBridge.activity );
				PTAdAdMobBridge.interstitial.setAdUnitId( PTAdAdMobBridge.interstitialId() );
				PTAdAdMobBridge.interstitial.setAdListener(new AdListener() {
		            @Override
		            public void onAdLoaded() {
		            	if(PTAdAdMobBridge.isInterstitialScheduledForShow){
		            		PTAdAdMobBridge.showFullScreen();
		            	}
		            }
		
		            @Override
		            public void onAdClosed() {
					    AdRequest adRequest = new AdRequest.Builder().build();
					    PTAdAdMobBridge.interstitial.loadAd(adRequest);
		            }
		            
		            @Override
		            public void onAdFailedToLoad(int errorCode) {
		            	if ( !isInterstitialScheduledForShow )
		            		return;
		            	
		            	PTAdAdMobBridge.interstitialDidFail();
		            }
		        });
		
				PTAdAdMobBridge.interstitial.loadAd(adRequest);
            }
        });
	}
	
	
	
	public static void showFullScreen(){
		Log.v(TAG, "showFullScreen");
		
		isInterstitialScheduledForShow = true;
		
		if(PTAdAdMobBridge.interstitial != null){
			PTAdAdMobBridge.s_activity.get().runOnUiThread( new Runnable() {
				public void run() {
					if(PTAdAdMobBridge.interstitial.isLoaded()){
						PTAdAdMobBridge.interstitial.show();
						PTAdAdMobBridge.isInterstitialScheduledForShow = false;
					}
					else{
						PTAdAdMobBridge.isInterstitialScheduledForShow = true;
					}
				}
			});
 		}
	}

	

	public static void showBannerAd(){
		Log.v(TAG, "showBannerAd");
		
		isBannerScheduledForShow = true;
		
		if(PTAdAdMobBridge.adView != null){
			PTAdAdMobBridge.s_activity.get().runOnUiThread( new Runnable() {
				public void run() {
					AdRequest adRequest = getAdRequest();
												   
					PTAdAdMobBridge.adView.loadAd(adRequest);
					PTAdAdMobBridge.adView.setAdListener(new AdListener() {		            
			            @Override
			            public void onAdFailedToLoad(int errorCode) {
			            	if ( !isBannerScheduledForShow )
			            		return;
			            	
							Log.v(TAG, "Banner Ad Failed To Load");
			            	PTAdAdMobBridge.bannerDidFail();
			            }
						
						@Override
						public void onAdLoaded() {
							Log.v(TAG, "Banner Ad Loaded");
							PTAdAdMobBridge.adView.setVisibility( isBannerScheduledForShow ? View.VISIBLE : View.INVISIBLE );
						}
			        });
					PTAdAdMobBridge.adView.setVisibility( View.VISIBLE );
				}
			});			
		}

		
		
	}

	public static void hideBannerAd(){
		Log.v(TAG, "hideBannerAd");
		
		isBannerScheduledForShow = false;
		
		if(PTAdAdMobBridge.adView != null){
	 		PTAdAdMobBridge.s_activity.get().runOnUiThread( new Runnable() {
	 			public void run() {
	 				PTAdAdMobBridge.adView.setVisibility( View.INVISIBLE );
	 			}
	 		});
		}
	}
	
	private static AdRequest getAdRequest(){
		// Create an ad request. Check your logcat output for the hashed device ID to
        // get test ads on a physical device. e.g.
        // "Use AdRequest.Builder.addTestDevice("ABCDEF012345") to get test ads on this device."
        AdRequest adRequest = new AdRequest.Builder()
				// uncomment to get test ads
                //.addTestDevice("YOUR_DEVICE_ID")
                .build();
		return adRequest;
	}

}
