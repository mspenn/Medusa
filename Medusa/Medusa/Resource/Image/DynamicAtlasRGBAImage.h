// Copyright (c) 2015 fjz13. All rights reserved.
// Use of this source code is governed by a MIT-style
// license that can be found in the LICENSE file.
#pragma once
#include "Resource/Image/RGBAImage.h"
#include "Geometry/Pack/SkylineBinPack.h"

MEDUSA_BEGIN;

class DynamicAtlasRGBAImage:public RGBAImage
{
public:
	DynamicAtlasRGBAImage(const FileIdRef& fileId,Size2U initImageSize,Size2U maxImageSize,PixelType pixelType,bool isPreMultiplyAlpha);
	virtual ~DynamicAtlasRGBAImage(void);
public:
	Size2U MaxImageSize() const { return mMaxImageSize; }
	void SetMaxImageSize(Size2U val) { mMaxImageSize = val; }

	bool IsExpandable() const { return mMaxImageSize<=mImageSize; }

	bool AddImageRect(const Size2U& size,int pitch,const MemoryData& imageData, PixelType pixelType,Rect2U& outRect,bool isFlipY=false,GraphicsPixelConvertMode mode=GraphicsPixelConvertMode::Normal);
protected:
	SkylineBinPack mPack;
	Size2U mMaxImageSize;
	
};

MEDUSA_END;