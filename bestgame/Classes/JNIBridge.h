#ifndef __JNIBridge_H__
#define __JNIBridge_H__

#include <jni.h>
#include "JNIBridgeCallback.h"

#include "cocos2d.h"

class JNIBridge
{

public:

    static void useSandbox();
    static void initialize(const char*, const char*, const char* auxData = NULL);
    static JNIBridge* instance(void);
    static void setNotificationToken(const char*);

    virtual ~JNIBridge();

    void deallocate(JNIEnv*, jobject);

    // methods called from C++ into the bridge
    bool launch(JNIBridgeCallback*);
    bool launchWithTournament(const char*, JNIBridgeCallback*);
    bool launchWithMatchResult(const char*, const char*, long, JNIBridgeCallback*);
    bool sdkSocialLoginCompleted(const char*);
    bool sdkSocialInviteCompleted();
    bool sdkSocialShareCompleted();

    void setOrientation(const char*);

    void syncChallengeCounts();
    int getChallengeCounts();

    // methods called from Java into the bridge
    void sdkCompletedWithExit(JNIEnv*, jobject);
    void sdkCompletedWithMatch(JNIEnv*, jobject, jstring, jstring, jlong, jint, jint);
    void sdkFailed(JNIEnv*, jobject, jstring, jobject);
    bool sdkSocialLogin(JNIEnv*, jobject, jboolean);
    bool sdkSocialInvite(JNIEnv*, jobject, jstring, jstring, jstring, jstring);
    bool sdkSocialShare(JNIEnv*, jobject, jstring, jstring, jstring, jstring);

private:

    static bool getEnv(JNIEnv**);

    JNIBridge();

    JNIBridgeCallback* m_callback;
    jobject m_nativeBridge;

};

#endif // __JNIBridge_H__
