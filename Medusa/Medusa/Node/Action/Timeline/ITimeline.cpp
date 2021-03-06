// Copyright (c) 2015 fjz13. All rights reserved.
// Use of this source code is governed by a MIT-style
// license that can be found in the LICENSE file.
#include "MedusaPreCompiled.h"
#include "ITimeline.h"
#include "Resource/Timeline/ITimelineModel.h"

MEDUSA_BEGIN;


ITimeline::ITimeline(const Share<ITimelineModel>& model, intp repeatCount, float beforeDelay /*= 0.f*/, float repeatDuration /*= 0.f*/, float afterDelay /*= 0.f*/, const StringRef& name /*= StringRef::Empty*/)
	:BaseFiniteRepeatableCountDownDelayAction(model->Duration(), repeatCount, beforeDelay, repeatDuration, afterDelay, name),
	mModel(model)
{

}

ITimeline::ITimeline(const Share<ITimelineModel>& model, bool isRepeatForever/*=false*/, float beforeDelay /*= 0.f*/, float repeatDuration /*= 0.f*/, float afterDelay /*= 0.f*/, const StringRef& name /*= StringRef::Empty*/)
	: BaseFiniteRepeatableCountDownDelayAction(model->Duration(), isRepeatForever, beforeDelay, repeatDuration, afterDelay, name),
	mModel(model)
{

}


ITimeline::ITimeline(const Share<ITimelineModel>& model, intp currentCount, intp repeatCount, float beforeDelay /*= 0.f*/, float repeatDuration /*= 0.f*/, float afterDelay /*= 0.f*/, const StringRef& name /*= StringRef::Empty*/)
	: BaseFiniteRepeatableCountDownDelayAction(model->Duration(), currentCount, repeatCount, beforeDelay, repeatDuration, afterDelay, name),
	mModel(model)
{

}

ITimeline::~ITimeline()
{

}

int ITimeline::FindFrameIndex(uint startIndex/* = 0*/) const
{
	uint outPrevFrameIndex;
	uint outNextFrameIndex;
	float outPercent;
	mModel->TryGetFrame(mElapsed, outPrevFrameIndex, outNextFrameIndex, outPercent, startIndex);
	return outNextFrameIndex;
}

int ITimeline::UpdateFrameIndex(uint startIndex /*= 0*/)
{
	if (mPrevFrameIndexFetched>=0)
	{
		startIndex = mPrevFrameIndexFetched;
	}
	uint outPrevFrameIndex;
	uint outNextFrameIndex;
	float outPercent;
	bool isFound=mModel->TryGetFrame(mElapsed, outPrevFrameIndex, outNextFrameIndex, outPercent, startIndex);
	if (isFound)
	{
		mPrevFrameIndexFetched = (int)outPrevFrameIndex;
	}
	return outNextFrameIndex;
}

void ITimeline::BuildClone(IAction& obj)
{
	BaseFiniteRepeatableCountDownDelayAction::BuildClone(obj);
	ITimeline& t = (ITimeline&)obj;
	t.mModel = mModel;
}

MEDUSA_END;

