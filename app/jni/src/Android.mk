LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := main

#path to include files writen in each MK file in each subdirs
#LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(SDL_PATH)/include ....... ....... .......

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../glm/

# Add your application source files here...
LOCAL_SRC_FILES := main.cpp

LOCAL_SHARED_LIBRARIES := SDL2 SDL2_image SDL2_mixer

LOCAL_LDLIBS := -lGLESv1_CM -lGLESv2 -llog


include $(BUILD_SHARED_LIBRARY)

