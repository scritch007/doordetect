#
# This is a project Makefile. It is assumed the directory this Makefile resides in is a
# project subdirectory.
#
IDF_PATH=/home/benjamin/dev/arduino/ESP8266_RTOS_SDK
PATH := $(PATH):$(IDF_PATH)/../xtensa-lx106-elf/bin/
SHELL := env PATH=$(PATH) /bin/bash
PROJECT_NAME := simple_wifi

include $(IDF_PATH)/make/project.mk

