/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbRamp
 *** Description: Рампа разгона / торможения.
 *** Version:
 ***     3.0: 2026-03-13/VA - LIB_PLC -
 *************************************************************************/

#include "FbRamp_fbt.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FbRamp_fbt_gen.cpp"
#endif

#include "core/datatypes/forte_bool.h"
#include "core/datatypes/forte_real.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

DEFINE_FIRMWARE_FB(FORTE_FbRamp, g_nStringIdFbRamp)

const CStringDictionary::TStringId FORTE_FbRamp::scmDataInputNames[] = {g_nStringIdIn, g_nStringIdScale, g_nStringIdTAcc, g_nStringIdTDec, g_nStringIdTs};
const CStringDictionary::TStringId FORTE_FbRamp::scmDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};
const CStringDictionary::TStringId FORTE_FbRamp::scmDataOutputNames[] = {g_nStringIdOut};
const CStringDictionary::TStringId FORTE_FbRamp::scmDataOutputTypeIds[] = {g_nStringIdREAL};
const TDataIOID FORTE_FbRamp::scmEIWith[] = {0, 1, 2, 3, 4, scmWithListDelimiter};
const TForteInt16 FORTE_FbRamp::scmEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbRamp::scmEventInputNames[] = {g_nStringIdREQ};
const TDataIOID FORTE_FbRamp::scmEOWith[] = {0, scmWithListDelimiter};
const TForteInt16 FORTE_FbRamp::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbRamp::scmEventOutputNames[] = {g_nStringIdCNF};
const SFBInterfaceSpec FORTE_FbRamp::scmFBInterfaceSpec = {
  1, scmEventInputNames, nullptr, scmEIWith, scmEIWithIndexes,
  1, scmEventOutputNames, nullptr, scmEOWith, scmEOWithIndexes,
  5, scmDataInputNames, scmDataInputTypeIds,
  1, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

const CStringDictionary::TStringId FORTE_FbRamp::scmInternalsNames[] = {g_nStringIdAccMode, g_nStringIdDecMode};
const CStringDictionary::TStringId FORTE_FbRamp::scmInternalsTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL};
const SInternalVarsInformation FORTE_FbRamp::scmInternalVars = {2, scmInternalsNames, scmInternalsTypeIds};

FORTE_FbRamp::FORTE_FbRamp(const CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer) :
    CSimpleFB(paContainer, scmFBInterfaceSpec, paInstanceNameId, &scmInternalVars),
    var_AccMode(false_BOOL),
    var_DecMode(false_BOOL),
    var_In(0.0_REAL),
    var_Scale(100.0_REAL),
    var_TAcc(5.0_REAL),
    var_TDec(5.0_REAL),
    var_Ts(0.1_REAL),
    var_Out(0.0_REAL),
    var_conn_Out(var_Out),
    conn_CNF(this, 0),
    conn_In(nullptr),
    conn_Scale(nullptr),
    conn_TAcc(nullptr),
    conn_TDec(nullptr),
    conn_Ts(nullptr),
    conn_Out(this, 0, &var_conn_Out) {
}

void FORTE_FbRamp::setInitialValues() {
  var_AccMode = false_BOOL;
  var_DecMode = false_BOOL;
  var_In = 0.0_REAL;
  var_Scale = 100.0_REAL;
  var_TAcc = 5.0_REAL;
  var_TDec = 5.0_REAL;
  var_Ts = 0.1_REAL;
  var_Out = 0.0_REAL;
}

void FORTE_FbRamp::executeEvent(const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch(paEIID) {
    case scmEventREQID:
      enterStateREQ(paECET);
      break;
    default:
      break;
  }
}

void FORTE_FbRamp::enterStateREQ(CEventChainExecutionThread *const paECET) {
  alg_REQ();
  sendOutputEvent(scmEventCNFID, paECET);
}

void FORTE_FbRamp::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventREQID: {
      readData(0, var_In, conn_In);
      readData(1, var_Scale, conn_Scale);
      readData(2, var_TAcc, conn_TAcc);
      readData(3, var_TDec, conn_TDec);
      readData(4, var_Ts, conn_Ts);
      break;
    }
    default:
      break;
  }
}

void FORTE_FbRamp::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventCNFID: {
      writeData(0, var_Out, conn_Out);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_FbRamp::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_In;
    case 1: return &var_Scale;
    case 2: return &var_TAcc;
    case 3: return &var_TDec;
    case 4: return &var_Ts;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbRamp::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_Out;
  }
  return nullptr;
}

CEventConnection *FORTE_FbRamp::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **FORTE_FbRamp::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_In;
    case 1: return &conn_Scale;
    case 2: return &conn_TAcc;
    case 3: return &conn_TDec;
    case 4: return &conn_Ts;
  }
  return nullptr;
}

CDataConnection *FORTE_FbRamp::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_Out;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbRamp::getVarInternal(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_AccMode;
    case 1: return &var_DecMode;
  }
  return nullptr;
}

void FORTE_FbRamp::alg_REQ(void) {

  #line 3 "FbRamp.fbt"
  if (func_LE(var_Scale, 0.0_REAL)) {
    #line 4 "FbRamp.fbt"
    var_Out = var_In;
  }
  else {
    #line 8 "FbRamp.fbt"
    var_AccMode = func_GT(var_In, var_Out);
    #line 9 "FbRamp.fbt"
    var_DecMode = func_LT(var_In, var_Out);
    #line 12 "FbRamp.fbt"
    if (var_AccMode) {
      #line 13 "FbRamp.fbt"
      if (func_LE(var_TAcc, 0.0_REAL)) {
        #line 14 "FbRamp.fbt"
        var_Out = var_In;
      }
      else {
        #line 16 "FbRamp.fbt"
        var_Out = func_ADD<CIEC_REAL>(var_Out, func_DIV<CIEC_REAL>(func_MUL<CIEC_REAL>(var_Ts, var_Scale), var_TAcc));
      }
    }
    #line 21 "FbRamp.fbt"
    if (var_DecMode) {
      #line 22 "FbRamp.fbt"
      if (func_LE(var_TDec, 0.0_REAL)) {
        #line 23 "FbRamp.fbt"
        var_Out = var_In;
      }
      else {
        #line 25 "FbRamp.fbt"
        var_Out = func_SUB<CIEC_REAL>(var_Out, func_DIV<CIEC_REAL>(func_MUL<CIEC_REAL>(var_Ts, var_Scale), var_TDec));
      }
    }
    #line 31 "FbRamp.fbt"
    if (func_OR<CIEC_BOOL>(func_OR<CIEC_BOOL>(func_AND<CIEC_BOOL>(var_AccMode, func_GE(var_Out, var_In)), func_AND<CIEC_BOOL>(var_DecMode, func_LE(var_Out, var_In))), func_EQ(var_In, var_Out))) {
      #line 33 "FbRamp.fbt"
      var_Out = var_In;
    }
  }
}
