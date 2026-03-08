/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbPIDcontrol
 *** Description: ПИД-регулятор.
 *** Version:
 ***     3.6: 2026-03-06/VA - LIB_PLC -
 *************************************************************************/

#include "FbPIDcontrol_fbt.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FbPIDcontrol_fbt_gen.cpp"
#endif

#include "core/datatypes/forte_bool.h"
#include "core/datatypes/forte_real.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

DEFINE_FIRMWARE_FB(FORTE_FbPIDcontrol, g_nStringIdFbPIDcontrol)

const CStringDictionary::TStringId FORTE_FbPIDcontrol::scmDataInputNames[] = {g_nStringIdPV, g_nStringIdSP, g_nStringIdKp, g_nStringIdKi, g_nStringIdKd, g_nStringIdKdf, g_nStringIdERMAX, g_nStringIdERMIN, g_nStringIdMVMAX, g_nStringIdMVMIN, g_nStringIdTs, g_nStringIdManual, g_nStringIdOnMan};
const CStringDictionary::TStringId FORTE_FbPIDcontrol::scmDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdBOOL};
const CStringDictionary::TStringId FORTE_FbPIDcontrol::scmDataOutputNames[] = {g_nStringIdMV};
const CStringDictionary::TStringId FORTE_FbPIDcontrol::scmDataOutputTypeIds[] = {g_nStringIdREAL};
const TDataIOID FORTE_FbPIDcontrol::scmEIWith[] = {0, 1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, scmWithListDelimiter};
const TForteInt16 FORTE_FbPIDcontrol::scmEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbPIDcontrol::scmEventInputNames[] = {g_nStringIdREQ};
const TDataIOID FORTE_FbPIDcontrol::scmEOWith[] = {0, scmWithListDelimiter};
const TForteInt16 FORTE_FbPIDcontrol::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbPIDcontrol::scmEventOutputNames[] = {g_nStringIdCNF};
const SFBInterfaceSpec FORTE_FbPIDcontrol::scmFBInterfaceSpec = {
  1, scmEventInputNames, nullptr, scmEIWith, scmEIWithIndexes,
  1, scmEventOutputNames, nullptr, scmEOWith, scmEOWithIndexes,
  13, scmDataInputNames, scmDataInputTypeIds,
  1, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

const CStringDictionary::TStringId FORTE_FbPIDcontrol::scmInternalsNames[] = {g_nStringIdER, g_nStringIdPpart, g_nStringIdIpart, g_nStringIdDpart, g_nStringIdDintegral, g_nStringIdAuto, g_nStringIdSw};
const CStringDictionary::TStringId FORTE_FbPIDcontrol::scmInternalsTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};
const SInternalVarsInformation FORTE_FbPIDcontrol::scmInternalVars = {7, scmInternalsNames, scmInternalsTypeIds};

FORTE_FbPIDcontrol::FORTE_FbPIDcontrol(const CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer) :
    CSimpleFB(paContainer, scmFBInterfaceSpec, paInstanceNameId, &scmInternalVars),
    var_ER(0.0_REAL),
    var_Ppart(0.0_REAL),
    var_Ipart(0.0_REAL),
    var_Dpart(0.0_REAL),
    var_Dintegral(0.0_REAL),
    var_Auto(0.0_REAL),
    var_Sw(0.0_REAL),
    var_PV(0.0_REAL),
    var_SP(0.0_REAL),
    var_Kp(0.01_REAL),
    var_Ki(0.01_REAL),
    var_Kd(0.0_REAL),
    var_Kdf(1.0_REAL),
    var_ERMAX(0.001_REAL),
    var_ERMIN(-0.001_REAL),
    var_MVMAX(100.0_REAL),
    var_MVMIN(0.0_REAL),
    var_Ts(0.1_REAL),
    var_Manual(25.0_REAL),
    var_OnMan(false_BOOL),
    var_MV(0.0_REAL),
    var_conn_MV(var_MV),
    conn_CNF(this, 0),
    conn_PV(nullptr),
    conn_SP(nullptr),
    conn_Kp(nullptr),
    conn_Ki(nullptr),
    conn_Kd(nullptr),
    conn_Kdf(nullptr),
    conn_ERMAX(nullptr),
    conn_ERMIN(nullptr),
    conn_MVMAX(nullptr),
    conn_MVMIN(nullptr),
    conn_Ts(nullptr),
    conn_Manual(nullptr),
    conn_OnMan(nullptr),
    conn_MV(this, 0, &var_conn_MV) {
}

void FORTE_FbPIDcontrol::setInitialValues() {
  var_ER = 0.0_REAL;
  var_Ppart = 0.0_REAL;
  var_Ipart = 0.0_REAL;
  var_Dpart = 0.0_REAL;
  var_Dintegral = 0.0_REAL;
  var_Auto = 0.0_REAL;
  var_Sw = 0.0_REAL;
  var_PV = 0.0_REAL;
  var_SP = 0.0_REAL;
  var_Kp = 0.01_REAL;
  var_Ki = 0.01_REAL;
  var_Kd = 0.0_REAL;
  var_Kdf = 1.0_REAL;
  var_ERMAX = 0.001_REAL;
  var_ERMIN = -0.001_REAL;
  var_MVMAX = 100.0_REAL;
  var_MVMIN = 0.0_REAL;
  var_Ts = 0.1_REAL;
  var_Manual = 25.0_REAL;
  var_OnMan = false_BOOL;
  var_MV = 0.0_REAL;
}

void FORTE_FbPIDcontrol::executeEvent(const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch(paEIID) {
    case scmEventREQID:
      enterStateREQ(paECET);
      break;
    default:
      break;
  }
}

void FORTE_FbPIDcontrol::enterStateREQ(CEventChainExecutionThread *const paECET) {
  alg_REQ();
  sendOutputEvent(scmEventCNFID, paECET);
}

void FORTE_FbPIDcontrol::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventREQID: {
      readData(0, var_PV, conn_PV);
      readData(1, var_SP, conn_SP);
      readData(3, var_Ki, conn_Ki);
      readData(4, var_Kd, conn_Kd);
      readData(5, var_Kdf, conn_Kdf);
      readData(6, var_ERMAX, conn_ERMAX);
      readData(7, var_ERMIN, conn_ERMIN);
      readData(8, var_MVMAX, conn_MVMAX);
      readData(9, var_MVMIN, conn_MVMIN);
      readData(10, var_Ts, conn_Ts);
      readData(11, var_Manual, conn_Manual);
      readData(12, var_OnMan, conn_OnMan);
      break;
    }
    default:
      break;
  }
}

void FORTE_FbPIDcontrol::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventCNFID: {
      writeData(0, var_MV, conn_MV);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_FbPIDcontrol::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_PV;
    case 1: return &var_SP;
    case 2: return &var_Kp;
    case 3: return &var_Ki;
    case 4: return &var_Kd;
    case 5: return &var_Kdf;
    case 6: return &var_ERMAX;
    case 7: return &var_ERMIN;
    case 8: return &var_MVMAX;
    case 9: return &var_MVMIN;
    case 10: return &var_Ts;
    case 11: return &var_Manual;
    case 12: return &var_OnMan;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbPIDcontrol::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_MV;
  }
  return nullptr;
}

CEventConnection *FORTE_FbPIDcontrol::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **FORTE_FbPIDcontrol::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_PV;
    case 1: return &conn_SP;
    case 2: return &conn_Kp;
    case 3: return &conn_Ki;
    case 4: return &conn_Kd;
    case 5: return &conn_Kdf;
    case 6: return &conn_ERMAX;
    case 7: return &conn_ERMIN;
    case 8: return &conn_MVMAX;
    case 9: return &conn_MVMIN;
    case 10: return &conn_Ts;
    case 11: return &conn_Manual;
    case 12: return &conn_OnMan;
  }
  return nullptr;
}

CDataConnection *FORTE_FbPIDcontrol::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_MV;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbPIDcontrol::getVarInternal(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_ER;
    case 1: return &var_Ppart;
    case 2: return &var_Ipart;
    case 3: return &var_Dpart;
    case 4: return &var_Dintegral;
    case 5: return &var_Auto;
    case 6: return &var_Sw;
  }
  return nullptr;
}

void FORTE_FbPIDcontrol::alg_REQ(void) {

  #line 4 "FbPIDcontrol.fbt"
  var_ER = func_SUB<CIEC_REAL>(var_SP, var_PV);
  #line 7 "FbPIDcontrol.fbt"
  if (func_AND<CIEC_BOOL>(func_LT(var_ERMIN, var_ER), func_LT(var_ER, var_ERMAX))) {
    #line 8 "FbPIDcontrol.fbt"
    var_ER = 0.0_REAL;
  }
  #line 12 "FbPIDcontrol.fbt"
  var_Ppart = func_MUL<CIEC_REAL>(var_Kp, var_ER);
  #line 15 "FbPIDcontrol.fbt"
  if (func_EQ(var_Ki, 0.0_REAL)) {
    #line 16 "FbPIDcontrol.fbt"
    var_Ipart = 0.0_REAL;
  }
  else {
    #line 18 "FbPIDcontrol.fbt"
    var_Ipart = func_ADD<CIEC_REAL>(var_Ipart, func_MUL<CIEC_REAL>(func_MUL<CIEC_REAL>(var_Ki, var_ER), var_Ts));
  }
  #line 22 "FbPIDcontrol.fbt"
  if (func_EQ(var_Kd, 0.0_REAL)) {
    #line 23 "FbPIDcontrol.fbt"
    var_Dpart = 0.0_REAL;
    #line 24 "FbPIDcontrol.fbt"
    var_Dintegral = 0.0_REAL;
  }
  else {
    #line 26 "FbPIDcontrol.fbt"
    var_Dpart = func_MUL<CIEC_REAL>(func_SUB<CIEC_REAL>(func_MUL<CIEC_REAL>(var_ER, var_Kd), var_Dintegral), var_Kdf);
    #line 27 "FbPIDcontrol.fbt"
    var_Dintegral = func_ADD<CIEC_REAL>(var_Dintegral, func_MUL<CIEC_REAL>(var_Dpart, var_Ts));
  }
  #line 31 "FbPIDcontrol.fbt"
  var_Auto = func_ADD<CIEC_REAL>(func_ADD<CIEC_REAL>(var_Ppart, var_Ipart), var_Dpart);
  #line 34 "FbPIDcontrol.fbt"
  if (var_OnMan) {
    #line 35 "FbPIDcontrol.fbt"
    var_Sw = var_Manual;
  }
  else {
    #line 37 "FbPIDcontrol.fbt"
    var_Sw = var_Auto;
  }
  #line 41 "FbPIDcontrol.fbt"
  if (func_GE(var_Sw, var_MVMAX)) {
    #line 42 "FbPIDcontrol.fbt"
    var_MV = var_MVMAX;
    #line 44 "FbPIDcontrol.fbt"
    var_Ipart = func_SUB<CIEC_REAL>(var_MV, func_ADD<CIEC_REAL>(var_Ppart, var_Dpart));
  }
  #line 48 "FbPIDcontrol.fbt"
  if (func_LE(var_Sw, var_MVMIN)) {
    #line 49 "FbPIDcontrol.fbt"
    var_MV = var_MVMIN;
    #line 51 "FbPIDcontrol.fbt"
    var_Ipart = func_SUB<CIEC_REAL>(var_MV, func_ADD<CIEC_REAL>(var_Ppart, var_Dpart));
  }
  #line 55 "FbPIDcontrol.fbt"
  if (func_AND<CIEC_BOOL>(func_LT(var_MVMIN, var_Sw), func_LT(var_Sw, var_MVMAX))) {
    #line 56 "FbPIDcontrol.fbt"
    var_MV = var_Sw;
    #line 57 "FbPIDcontrol.fbt"
    if (var_OnMan) {
      #line 59 "FbPIDcontrol.fbt"
      var_Ipart = func_SUB<CIEC_REAL>(var_MV, func_ADD<CIEC_REAL>(var_Ppart, var_Dpart));
    }
  }
}
