/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*-
 *
 * The contents of this file are subject to the Netscape Public License
 * Version 1.0 (the "NPL"); you may not use this file except in
 * compliance with the NPL.  You may obtain a copy of the NPL at
 * http://www.mozilla.org/NPL/
 *
 * Software distributed under the NPL is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the NPL
 * for the specific language governing rights and limitations under the
 * NPL.
 *
 * The Initial Developer of this code under the NPL is Netscape
 * Communications Corporation.  Portions created by Netscape are
 * Copyright (C) 1998 Netscape Communications Corporation.  All Rights
 * Reserved.
 */

#ifndef nsRenderingContextMac_h___
#define nsRenderingContextMac_h___

#include "nsIRenderingContext.h"
#include <QDOffscreen.h>
#include "nsCRT.h"

class nsIFontMetrics;
class nsIDeviceContext;
class nsIRegion;
class nsFont;
class nsTransform2D;
class nsVoidArray;

class GraphicState;

typedef GrafPtr nsDrawingSurfaceMac;

//------------------------------------------------------------------------

class nsRenderingContextMac : public nsIRenderingContext
{
public:
  nsRenderingContextMac();
  ~nsRenderingContextMac();

  void* operator new(size_t sz) {
    void* rv = new char[sz];
    nsCRT::zero(rv, sz);
    return rv;
  }

  NS_DECL_ISUPPORTS

  NS_IMETHOD Init(nsIDeviceContext* aContext, nsIWidget *aWindow);
  NS_IMETHOD Init(nsIDeviceContext* aContext, nsDrawingSurface aSurface);

  NS_IMETHOD Reset(void);
  NS_IMETHOD GetDeviceContext(nsIDeviceContext *&aContext);
  NS_IMETHOD SelectOffScreenDrawingSurface(nsDrawingSurface aSurface);
  NS_IMETHOD GetHints(PRUint32& aResult){return NS_OK;};
  NS_IMETHOD PushState(void);
  NS_IMETHOD PopState(PRBool &aClipEmpty);
  NS_IMETHOD IsVisibleRect(const nsRect& aRect, PRBool &aVisible);
  NS_IMETHOD SetClipRect(const nsRect& aRect, nsClipCombine aCombine, PRBool &aClipEmpty);
  NS_IMETHOD GetClipRect(nsRect &aRect, PRBool &aClipValid);
  NS_IMETHOD SetClipRegion(const nsIRegion& aRegion, nsClipCombine aCombine, PRBool &aClipEmpty);
  NS_IMETHOD GetClipRegion(nsIRegion **aRegion);
  NS_IMETHOD SetLineStyle(nsLineStyle aLineStyle);
  NS_IMETHOD GetLineStyle(nsLineStyle &aLineStyle);
  NS_IMETHOD SetColor(nscolor aColor);
  NS_IMETHOD GetColor(nscolor &aColor) const;
  NS_IMETHOD SetFont(const nsFont& aFont);
  NS_IMETHOD SetFont(nsIFontMetrics *aFontMetrics);
  NS_IMETHOD GetFontMetrics(nsIFontMetrics *&aFontMetrics);
  NS_IMETHOD Translate(nscoord aX, nscoord aY);
  NS_IMETHOD Scale(float aSx, float aSy);
  NS_IMETHOD GetCurrentTransform(nsTransform2D *&aTransform);
  NS_IMETHOD CreateDrawingSurface(nsRect *aBounds, PRUint32 aSurfFlags, nsDrawingSurface &aSurface);
  NS_IMETHOD DestroyDrawingSurface(nsDrawingSurface aDS);
  NS_IMETHOD DrawLine(nscoord aX0, nscoord aY0, nscoord aX1, nscoord aY1);
  NS_IMETHOD DrawPolyline(const nsPoint aPoints[], PRInt32 aNumPoints);
  NS_IMETHOD DrawRect(const nsRect& aRect);
  NS_IMETHOD DrawRect(nscoord aX, nscoord aY, nscoord aWidth, nscoord aHeight);
  NS_IMETHOD FillRect(const nsRect& aRect);
  NS_IMETHOD FillRect(nscoord aX, nscoord aY, nscoord aWidth, nscoord aHeight);
  NS_IMETHOD DrawPolygon(const nsPoint aPoints[], PRInt32 aNumPoints);
  NS_IMETHOD FillPolygon(const nsPoint aPoints[], PRInt32 aNumPoints);
  NS_IMETHOD DrawEllipse(const nsRect& aRect);
  NS_IMETHOD DrawEllipse(nscoord aX, nscoord aY, nscoord aWidth, nscoord aHeight);
  NS_IMETHOD FillEllipse(const nsRect& aRect);
  NS_IMETHOD FillEllipse(nscoord aX, nscoord aY, nscoord aWidth, nscoord aHeight);
  NS_IMETHOD DrawArc(const nsRect& aRect,float aStartAngle, float aEndAngle);
  NS_IMETHOD DrawArc(nscoord aX, nscoord aY, nscoord aWidth, nscoord aHeight,float aStartAngle, float aEndAngle);
  NS_IMETHOD FillArc(const nsRect& aRect,float aStartAngle, float aEndAngle);
  NS_IMETHOD FillArc(nscoord aX, nscoord aY, nscoord aWidth, nscoord aHeight,float aStartAngle, float aEndAngle);
  NS_IMETHOD GetWidth(char aC, nscoord &aWidth);
  NS_IMETHOD GetWidth(PRUnichar aC, nscoord &aWidth);
  NS_IMETHOD GetWidth(const nsString& aString, nscoord &aWidth);
  NS_IMETHOD GetWidth(const char *aString, nscoord &aWidth);
  NS_IMETHOD GetWidth(const char* aString, PRUint32 aLength, nscoord& aWidth);
  NS_IMETHOD GetWidth(const PRUnichar *aString, PRUint32 aLength, nscoord &aWidth);
  NS_IMETHOD DrawString(const char *aString, PRUint32 aLength,nscoord aX, nscoord aY,nscoord aWidth, const nscoord* aSpacing);
  NS_IMETHOD DrawString(const PRUnichar *aString, PRUint32 aLength, nscoord aX, nscoord aY,nscoord aWidth, const nscoord* aSpacing);
  NS_IMETHOD DrawString(const nsString& aString, nscoord aX, nscoord aY,nscoord aWidth, const nscoord* aSpacing);
  NS_IMETHOD DrawImage(nsIImage *aImage, nscoord aX, nscoord aY);
  NS_IMETHOD DrawImage(nsIImage *aImage, nscoord aX, nscoord aY, nscoord aWidth, nscoord aHeight); 
  NS_IMETHOD DrawImage(nsIImage *aImage, const nsRect& aRect);
  NS_IMETHOD DrawImage(nsIImage *aImage, const nsRect& aSRect, const nsRect& aDRect);
  NS_IMETHOD CopyOffScreenBits(nsDrawingSurface aSrcSurf, PRInt32 aSrcX, PRInt32 aSrcY,
                               const nsRect &aDestBounds, PRUint32 aCopyFlags);

  //locals
  NS_IMETHOD CommonInit(void);
  NS_IMETHOD SetClipRectInPixels(const nsRect& aRect, nsClipCombine aCombine, PRBool &aClipEmpty);

protected:
	GrafPtr		mOldPort;

	inline void	StartDraw()
  				{
					::GetPort(&mOldPort);
					NS_ASSERTION((mCurrentBuffer != nsnull), "mCurrentBuffer is null");
					::SetPort(mCurrentBuffer);
  				}

	inline void	EndDraw()
  				{
					::SetPort(mOldPort);
  				}

	enum ClipMethod {
		clipToMainRegion,
		clipToClipRegion
	};
	void	SetQuickDrawEnvironment(GraphicState* aGraphicState, ClipMethod clipMethod);
	void	SelectDrawingSurface(nsDrawingSurfaceMac aSurface, GraphicState* aGraphicState);
	
protected:
	float             		mP2T; 				// Pixel to Twip conversion factor
	nsIDeviceContext *		mContext;

	nsDrawingSurfaceMac		mOriginalSurface;
	nsDrawingSurfaceMac		mFrontBuffer;		// screen port
	nsDrawingSurfaceMac		mCurrentBuffer;		// current drawing surface (= mGS->mRenderingSurface)

	// graphic state management
	GraphicState *			mGS;				// Pointer to the current graphic state
	nsVoidArray *			mGSArray;			// GraphicState array,  used when a surface gets selected
	nsVoidArray *			mSurfaceArray;		// Surface array,       used when a surface gets selected
	nsVoidArray *			mGSStack;			// GraphicStates stack, used for PushState/PopState
};

#endif /* nsRenderingContextMac_h___ */
