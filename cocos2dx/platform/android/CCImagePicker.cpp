/****************************************************************************
 Author: Luma (stubma@gmail.com)
 
 https://github.com/stubma/cocos2dx-classical
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

#include "CCImagePicker.h"
#include "JniHelper.h"

NS_CC_BEGIN

bool CCImagePicker::hasCamera() {
	JniMethodInfo t;
	JniHelper::getStaticMethodInfo(t, "org/cocos2dx/lib/CCImagePicker", "hasCamera", "()Z");
	bool ret = t.env->CallStaticBooleanMethod(t.classID, t.methodID);
    
    // release
    t.env->DeleteLocalRef(t.classID);
    
    // return
    return ret;
}

bool CCImagePicker::hasFrontCamera() {
	JniMethodInfo t;
	JniHelper::getStaticMethodInfo(t, "org/cocos2dx/lib/CCImagePicker", "hasFrontCamera", "()Z");
	bool ret = t.env->CallStaticBooleanMethod(t.classID, t.methodID);
    
    // release
    t.env->DeleteLocalRef(t.classID);
    
    // return
    return ret;
}

void CCImagePicker::pickFromCamera() {
	JniMethodInfo t;
	JniHelper::getStaticMethodInfo(t, "org/cocos2dx/lib/CCImagePicker", "pickFromCamera", "(Ljava/lang/String;JIIZZ)V");
	jstring jPath = t.env->NewStringUTF(m_path.c_str());
	t.env->CallStaticVoidMethod(t.classID,
                                t.methodID,
                                jPath,
                                (jlong)this,
                                m_expectedWidth,
                                m_expectedHeight,
                                m_useFrontCamera,
                                m_keepRatio);
    
    // release
    t.env->DeleteLocalRef(t.classID);
}

void CCImagePicker::pickFromAlbum() {
	JniMethodInfo t;
	JniHelper::getStaticMethodInfo(t, "org/cocos2dx/lib/CCImagePicker", "pickFromAlbum", "(Ljava/lang/String;JIIZ)V");
	jstring jPath = t.env->NewStringUTF(m_path.c_str());
	t.env->CallStaticVoidMethod(t.classID,
                                t.methodID,
                                jPath,
                                (jlong)this,
                                m_expectedWidth,
                                m_expectedHeight,
                                m_keepRatio);
    
    // release
    t.env->DeleteLocalRef(t.classID);
}

NS_CC_END

#endif // #if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID