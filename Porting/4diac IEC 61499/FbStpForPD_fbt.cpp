/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbStpForPD
 *** Description: Аналоговый ПД-регулятор превращаем в дискретный ПИ.
 *** Version:
 ***     0.2: 2026-03-20/VA - LIB_PLC -
 *************************************************************************/

#include "FbStpForPD_fbt.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FbStpForPD_fbt_gen.cpp"
#endif

#include "core/datatypes/forte_bool.h"
#include "core/datatypes/forte_real.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

DEFINE_FIRMWARE_FB(FORTE_FbStpForPD, g_nStringIdFbStpForPD)

const CStringDictionary::TStringId FORTE_FbStpForPD::scmDataInputNames[] = {g_nStringIdInFromPD, g_nStringIdTimeOpen, g_nStringIdTimeClose, g_nStringIdTimeMin, g_nStringIdSmax, g_nStringIdSmin, g_nStringIdSensorOpen, g_nStringIdSensorClose, g_nStringIdTs, g_nStringIdReset};
const CStringDictionary::TStringId FORTE_FbStpForPD::scmDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdREAL, g_nStringIdBOOL};
const CStringDictionary::TStringId FORTE_FbStpForPD::scmDataOutputNames[] = {g_nStringIdCmdOpen, g_nStringIdCmdClose};
const CStringDictionary::TStringId FORTE_FbStpForPD::scmDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL};
const TDataIOID FORTE_FbStpForPD::scmEIWith[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, scmWithListDelimiter};
const TForteInt16 FORTE_FbStpForPD::scmEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbStpForPD::scmEventInputNames[] = {g_nStringIdREQ};
const TDataIOID FORTE_FbStpForPD::scmEOWith[] = {0, 1, scmWithListDelimiter};
const TForteInt16 FORTE_FbStpForPD::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbStpForPD::scmEventOutputNames[] = {g_nStringIdCNF};
const SFBInterfaceSpec FORTE_FbStpForPD::scmFBInterfaceSpec = {
  1, scmEventInputNames, nullptr, scmEIWith, scmEIWithIndexes,
  1, scmEventOutputNames, nullptr, scmEOWith, scmEOWithIndexes,
  10, scmDataInputNames, scmDataInputTypeIds,
  2, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

const CStringDictionary::TStringId FORTE_FbStpForPD::scmInternalsNames[] = {g_nStringIdPos, g_nStringIdVin, g_nStringIdVopen, g_nStringIdVclose, g_nStringIdSopenMin, g_nStringIdScloseMin};
const CStringDictionary::TStringId FORTE_FbStpForPD::scmInternalsTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};
const SInternalVarsInformation FORTE_FbStpForPD::scmInternalVars = {6, scmInternalsNames, scmInternalsTypeIds};

FORTE_FbStpForPD::FORTE_FbStpForPD(const CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer) :
    CSimpleFB(paContainer, scmFBInterfaceSpec, paInstanceNameId, &scmInternalVars),
    var_Pos(0.0_REAL),
    var_Vin(0.0_REAL),
    var_Vopen(0.0_REAL),
    var_Vclose(0.0_REAL),
    var_SopenMin(0.0_REAL),
    var_ScloseMin(0.0_REAL),
    var_InFromPD(0.0_REAL),
    var_TimeOpen(60.0_REAL),
    var_TimeClose(50.0_REAL),
    var_TimeMin(0.5_REAL),
    var_Smax(10.0_REAL),
    var_Smin(-10.0_REAL),
    var_SensorOpen(false_BOOL),
    var_SensorClose(false_BOOL),
    var_Ts(0.1_REAL),
    var_Reset(false_BOOL),
    var_CmdOpen(false_BOOL),
    var_CmdClose(false_BOOL),
    var_conn_CmdOpen(var_CmdOpen),
    var_conn_CmdClose(var_CmdClose),
    conn_CNF(this, 0),
    conn_InFromPD(nullptr),
    conn_TimeOpen(nullptr),
    conn_TimeClose(nullptr),
    conn_TimeMin(nullptr),
    conn_Smax(nullptr),
    conn_Smin(nullptr),
    conn_SensorOpen(nullptr),
    conn_SensorClose(nullptr),
    conn_Ts(nullptr),
    conn_Reset(nullptr),
    conn_CmdOpen(this, 0, &var_conn_CmdOpen),
    conn_CmdClose(this, 1, &var_conn_CmdClose) {
}

void FORTE_FbStpForPD::setInitialValues() {
  var_Pos = 0.0_REAL;
  var_Vin = 0.0_REAL;
  var_Vopen = 0.0_REAL;
  var_Vclose = 0.0_REAL;
  var_SopenMin = 0.0_REAL;
  var_ScloseMin = 0.0_REAL;
  var_InFromPD = 0.0_REAL;
  var_TimeOpen = 60.0_REAL;
  var_TimeClose = 50.0_REAL;
  var_TimeMin = 0.5_REAL;
  var_Smax = 10.0_REAL;
  var_Smin = -10.0_REAL;
  var_SensorOpen = false_BOOL;
  var_SensorClose = false_BOOL;
  var_Ts = 0.1_REAL;
  var_Reset = false_BOOL;
  var_CmdOpen = false_BOOL;
  var_CmdClose = false_BOOL;
}

void FORTE_FbStpForPD::executeEvent(const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch(paEIID) {
    case scmEventREQID:
      enterStateREQ(paECET);
      break;
    default:
      break;
  }
}

void FORTE_FbStpForPD::enterStateREQ(CEventChainExecutionThread *const paECET) {
  alg_REQ();
  sendOutputEvent(scmEventCNFID, paECET);
}

void FORTE_FbStpForPD::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventREQID: {
      readData(0, var_InFromPD, conn_InFromPD);
      readData(1, var_TimeOpen, conn_TimeOpen);
      readData(2, var_TimeClose, conn_TimeClose);
      readData(3, var_TimeMin, conn_TimeMin);
      readData(4, var_Smax, conn_Smax);
      readData(5, var_Smin, conn_Smin);
      readData(6, var_SensorOpen, conn_SensorOpen);
      readData(7, var_SensorClose, conn_SensorClose);
      readData(8, var_Ts, conn_Ts);
      readData(9, var_Reset, conn_Reset);
      break;
    }
    default:
      break;
  }
}

void FORTE_FbStpForPD::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventCNFID: {
      writeData(0, var_CmdOpen, conn_CmdOpen);
      writeData(1, var_CmdClose, conn_CmdClose);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_FbStpForPD::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_InFromPD;
    case 1: return &var_TimeOpen;
    case 2: return &var_TimeClose;
    case 3: return &var_TimeMin;
    case 4: return &var_Smax;
    case 5: return &var_Smin;
    case 6: return &var_SensorOpen;
    case 7: return &var_SensorClose;
    case 8: return &var_Ts;
    case 9: return &var_Reset;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbStpForPD::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_CmdOpen;
    case 1: return &var_CmdClose;
  }
  return nullptr;
}

CEventConnection *FORTE_FbStpForPD::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **FORTE_FbStpForPD::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_InFromPD;
    case 1: return &conn_TimeOpen;
    case 2: return &conn_TimeClose;
    case 3: return &conn_TimeMin;
    case 4: return &conn_Smax;
    case 5: return &conn_Smin;
    case 6: return &conn_SensorOpen;
    case 7: return &conn_SensorClose;
    case 8: return &conn_Ts;
    case 9: return &conn_Reset;
  }
  return nullptr;
}

CDataConnection *FORTE_FbStpForPD::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CmdOpen;
    case 1: return &conn_CmdClose;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbStpForPD::getVarInternal(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_Pos;
    case 1: return &var_Vin;
    case 2: return &var_Vopen;
    case 3: return &var_Vclose;
    case 4: return &var_SopenMin;
    case 5: return &var_ScloseMin;
  }
  return nullptr;
}

void FORTE_FbStpForPD::alg_REQ(void) {

  #line 4 "FbStpForPD.fbt"
  var_Vin = var_InFromPD;
  #line 5 "FbStpForPD.fbt"
  var_Vopen = func_DIV<CIEC_REAL>(100.0_REAL, var_TimeOpen);
  #line 6 "FbStpForPD.fbt"
  var_Vclose = func_DIV<CIEC_REAL>(100.0_REAL, var_TimeClose);
  #line 7 "FbStpForPD.fbt"
  var_SopenMin = func_MUL<CIEC_REAL>(var_Vopen, var_TimeMin);
  #line 8 "FbStpForPD.fbt"
  var_ScloseMin = func_MUL<CIEC_REAL>(var_Vclose, var_TimeMin);
  #line 9 "FbStpForPD.fbt"
  var_Pos = func_ADD<CIEC_REAL>(var_Pos, func_MUL<CIEC_REAL>(var_Vin, var_Ts));
  #line 11 "FbStpForPD.fbt"
  if (var_Reset) {
    #line 12 "FbStpForPD.fbt"
    var_Pos = 0.0_REAL;
  }
  #line 16 "FbStpForPD.fbt"
  if (func_GE(var_Pos, var_SopenMin)) {
    #line 17 "FbStpForPD.fbt"
    var_CmdOpen = true_BOOL;
  }
  #line 20 "FbStpForPD.fbt"
  if (func_OR<CIEC_BOOL>(func_LE(var_Pos, 0.0_REAL), var_SensorOpen)) {
    #line 21 "FbStpForPD.fbt"
    var_CmdOpen = false_BOOL;
  }
  #line 24 "FbStpForPD.fbt"
  if (var_CmdOpen) {
    #line 25 "FbStpForPD.fbt"
    var_Pos = func_SUB<CIEC_REAL>(var_Pos, func_MUL<CIEC_REAL>(var_Vopen, var_Ts));
  }
  #line 29 "FbStpForPD.fbt"
  if (func_LE(var_Pos, func_MUL<CIEC_REAL>(var_ScloseMin, -1.0_REAL))) {
    #line 30 "FbStpForPD.fbt"
    var_CmdClose = true_BOOL;
  }
  #line 33 "FbStpForPD.fbt"
  if (func_OR<CIEC_BOOL>(func_GE(var_Pos, 0.0_REAL), var_SensorClose)) {
    #line 34 "FbStpForPD.fbt"
    var_CmdClose = false_BOOL;
  }
  #line 37 "FbStpForPD.fbt"
  if (var_CmdClose) {
    #line 38 "FbStpForPD.fbt"
    var_Pos = func_ADD<CIEC_REAL>(var_Pos, func_MUL<CIEC_REAL>(var_Vclose, var_Ts));
  }
  #line 42 "FbStpForPD.fbt"
  if (func_GE(var_Pos, var_Smax)) {
    #line 43 "FbStpForPD.fbt"
    var_Pos = var_Smax;
  }
  #line 46 "FbStpForPD.fbt"
  if (func_LE(var_Pos, var_Smin)) {
    #line 47 "FbStpForPD.fbt"
    var_Pos = var_Smin;
  }
}
