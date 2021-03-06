/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "unity.h"
#include "cmock.h"
#include "mock_analog.h"

static const char* CMockString_estado = "estado";
static const char* CMockString_getValorInstantaneoPinBateria = "getValorInstantaneoPinBateria";
static const char* CMockString_setEstadoLEDPanelFrontal = "setEstadoLEDPanelFrontal";

typedef struct _CMOCK_getValorInstantaneoPinBateria_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int ReturnVal;
  int CallOrder;

} CMOCK_getValorInstantaneoPinBateria_CALL_INSTANCE;

typedef struct _CMOCK_setEstadoLEDPanelFrontal_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int CallOrder;
  int Expected_estado;

} CMOCK_setEstadoLEDPanelFrontal_CALL_INSTANCE;

static struct mock_analogInstance
{
  int getValorInstantaneoPinBateria_IgnoreBool;
  int getValorInstantaneoPinBateria_FinalReturn;
  CMOCK_getValorInstantaneoPinBateria_CALLBACK getValorInstantaneoPinBateria_CallbackFunctionPointer;
  int getValorInstantaneoPinBateria_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE getValorInstantaneoPinBateria_CallInstance;
  int setEstadoLEDPanelFrontal_IgnoreBool;
  CMOCK_setEstadoLEDPanelFrontal_CALLBACK setEstadoLEDPanelFrontal_CallbackFunctionPointer;
  int setEstadoLEDPanelFrontal_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE setEstadoLEDPanelFrontal_CallInstance;
} Mock;

extern jmp_buf AbortFrame;
extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_analog_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  if (Mock.getValorInstantaneoPinBateria_IgnoreBool)
    Mock.getValorInstantaneoPinBateria_CallInstance = CMOCK_GUTS_NONE;
  UNITY_SET_DETAIL(CMockString_getValorInstantaneoPinBateria);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.getValorInstantaneoPinBateria_CallInstance, cmock_line, CMockStringCalledLess);
  if (Mock.getValorInstantaneoPinBateria_CallbackFunctionPointer != NULL)
    Mock.getValorInstantaneoPinBateria_CallInstance = CMOCK_GUTS_NONE;
  if (Mock.setEstadoLEDPanelFrontal_IgnoreBool)
    Mock.setEstadoLEDPanelFrontal_CallInstance = CMOCK_GUTS_NONE;
  UNITY_SET_DETAIL(CMockString_setEstadoLEDPanelFrontal);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.setEstadoLEDPanelFrontal_CallInstance, cmock_line, CMockStringCalledLess);
  if (Mock.setEstadoLEDPanelFrontal_CallbackFunctionPointer != NULL)
    Mock.setEstadoLEDPanelFrontal_CallInstance = CMOCK_GUTS_NONE;
}

void mock_analog_Init(void)
{
  mock_analog_Destroy();
}

void mock_analog_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  Mock.getValorInstantaneoPinBateria_CallbackFunctionPointer = NULL;
  Mock.getValorInstantaneoPinBateria_CallbackCalls = 0;
  Mock.setEstadoLEDPanelFrontal_CallbackFunctionPointer = NULL;
  Mock.setEstadoLEDPanelFrontal_CallbackCalls = 0;
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

int getValorInstantaneoPinBateria(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_getValorInstantaneoPinBateria_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_getValorInstantaneoPinBateria);
  cmock_call_instance = (CMOCK_getValorInstantaneoPinBateria_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.getValorInstantaneoPinBateria_CallInstance);
  Mock.getValorInstantaneoPinBateria_CallInstance = CMock_Guts_MemNext(Mock.getValorInstantaneoPinBateria_CallInstance);
  if (Mock.getValorInstantaneoPinBateria_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    if (cmock_call_instance == NULL)
      return Mock.getValorInstantaneoPinBateria_FinalReturn;
    Mock.getValorInstantaneoPinBateria_FinalReturn = cmock_call_instance->ReturnVal;
    return cmock_call_instance->ReturnVal;
  }
  if (Mock.getValorInstantaneoPinBateria_CallbackFunctionPointer != NULL)
  {
    return Mock.getValorInstantaneoPinBateria_CallbackFunctionPointer(Mock.getValorInstantaneoPinBateria_CallbackCalls++);
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void getValorInstantaneoPinBateria_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_getValorInstantaneoPinBateria_CALL_INSTANCE));
  CMOCK_getValorInstantaneoPinBateria_CALL_INSTANCE* cmock_call_instance = (CMOCK_getValorInstantaneoPinBateria_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.getValorInstantaneoPinBateria_CallInstance = CMock_Guts_MemChain(Mock.getValorInstantaneoPinBateria_CallInstance, cmock_guts_index);
  Mock.getValorInstantaneoPinBateria_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.getValorInstantaneoPinBateria_IgnoreBool = (int)1;
}

void getValorInstantaneoPinBateria_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_getValorInstantaneoPinBateria_CALL_INSTANCE));
  CMOCK_getValorInstantaneoPinBateria_CALL_INSTANCE* cmock_call_instance = (CMOCK_getValorInstantaneoPinBateria_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.getValorInstantaneoPinBateria_CallInstance = CMock_Guts_MemChain(Mock.getValorInstantaneoPinBateria_CallInstance, cmock_guts_index);
  Mock.getValorInstantaneoPinBateria_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  cmock_call_instance->ReturnVal = cmock_to_return;
  UNITY_CLR_DETAILS();
}

void getValorInstantaneoPinBateria_StubWithCallback(CMOCK_getValorInstantaneoPinBateria_CALLBACK Callback)
{
  Mock.getValorInstantaneoPinBateria_IgnoreBool = (int)0;
  Mock.getValorInstantaneoPinBateria_CallbackFunctionPointer = Callback;
}

void setEstadoLEDPanelFrontal(int estado)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_setEstadoLEDPanelFrontal_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_setEstadoLEDPanelFrontal);
  cmock_call_instance = (CMOCK_setEstadoLEDPanelFrontal_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.setEstadoLEDPanelFrontal_CallInstance);
  Mock.setEstadoLEDPanelFrontal_CallInstance = CMock_Guts_MemNext(Mock.setEstadoLEDPanelFrontal_CallInstance);
  if (Mock.setEstadoLEDPanelFrontal_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    return;
  }
  if (Mock.setEstadoLEDPanelFrontal_CallbackFunctionPointer != NULL)
  {
    Mock.setEstadoLEDPanelFrontal_CallbackFunctionPointer(estado, Mock.setEstadoLEDPanelFrontal_CallbackCalls++);
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  {
    UNITY_SET_DETAILS(CMockString_setEstadoLEDPanelFrontal,CMockString_estado);
    UNITY_TEST_ASSERT_EQUAL_INT(cmock_call_instance->Expected_estado, estado, cmock_line, CMockStringMismatch);
  }
  UNITY_CLR_DETAILS();
}

void CMockExpectParameters_setEstadoLEDPanelFrontal(CMOCK_setEstadoLEDPanelFrontal_CALL_INSTANCE* cmock_call_instance, int estado)
{
  cmock_call_instance->Expected_estado = estado;
}

void setEstadoLEDPanelFrontal_CMockIgnore(void)
{
  Mock.setEstadoLEDPanelFrontal_IgnoreBool = (int)1;
}

void setEstadoLEDPanelFrontal_CMockExpect(UNITY_LINE_TYPE cmock_line, int estado)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_setEstadoLEDPanelFrontal_CALL_INSTANCE));
  CMOCK_setEstadoLEDPanelFrontal_CALL_INSTANCE* cmock_call_instance = (CMOCK_setEstadoLEDPanelFrontal_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.setEstadoLEDPanelFrontal_CallInstance = CMock_Guts_MemChain(Mock.setEstadoLEDPanelFrontal_CallInstance, cmock_guts_index);
  Mock.setEstadoLEDPanelFrontal_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_setEstadoLEDPanelFrontal(cmock_call_instance, estado);
  UNITY_CLR_DETAILS();
}

void setEstadoLEDPanelFrontal_StubWithCallback(CMOCK_setEstadoLEDPanelFrontal_CALLBACK Callback)
{
  Mock.setEstadoLEDPanelFrontal_IgnoreBool = (int)0;
  Mock.setEstadoLEDPanelFrontal_CallbackFunctionPointer = Callback;
}

