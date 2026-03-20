/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbFilterNaN
 *** Description: Фильтр NaN и Inf для чисел REAL.
 *** Version:
 ***     2.2: 2026-03-20/VA - LIB_PLC -
 *************************************************************************/

#include "FbFilterNaN_fbt.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FbFilterNaN_fbt_gen.cpp"
#endif

#include "core/datatypes/forte_bool.h"
#include "core/datatypes/forte_dword.h"
#include "core/datatypes/forte_real.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

DEFINE_FIRMWARE_FB(FORTE_FbFilterNaN, g_nStringIdFbFilterNaN)

const CStringDictionary::TStringId FORTE_FbFilterNaN::scmDataInputNames[] = {g_nStringIdIn, g_nStringIdErrValue};
const CStringDictionary::TStringId FORTE_FbFilterNaN::scmDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL};
const CStringDictionary::TStringId FORTE_FbFilterNaN::scmDataOutputNames[] = {g_nStringIdOut, g_nStringIdErr};
const CStringDictionary::TStringId FORTE_FbFilterNaN::scmDataOutputTypeIds[] = {g_nStringIdREAL, g_nStringIdBOOL};
const TDataIOID FORTE_FbFilterNaN::scmEIWith[] = {0, 1, scmWithListDelimiter};
const TForteInt16 FORTE_FbFilterNaN::scmEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbFilterNaN::scmEventInputNames[] = {g_nStringIdREQ};
const TDataIOID FORTE_FbFilterNaN::scmEOWith[] = {0, 1, scmWithListDelimiter};
const TForteInt16 FORTE_FbFilterNaN::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbFilterNaN::scmEventOutputNames[] = {g_nStringIdCNF};
const SFBInterfaceSpec FORTE_FbFilterNaN::scmFBInterfaceSpec = {
  1, scmEventInputNames, nullptr, scmEIWith, scmEIWithIndexes,
  1, scmEventOutputNames, nullptr, scmEOWith, scmEOWithIndexes,
  2, scmDataInputNames, scmDataInputTypeIds,
  2, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

const CStringDictionary::TStringId FORTE_FbFilterNaN::scmInternalsNames[] = {g_nStringIdFlag_nan_1, g_nStringIdFlag_nan_2, g_nStringIdFlag_nan_3, g_nStringIdFlag_pos_inf, g_nStringIdFlag_neg_inf};
const CStringDictionary::TStringId FORTE_FbFilterNaN::scmInternalsTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL};
const SInternalVarsInformation FORTE_FbFilterNaN::scmInternalVars = {5, scmInternalsNames, scmInternalsTypeIds};

FORTE_FbFilterNaN::FORTE_FbFilterNaN(const CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer) :
    CSimpleFB(paContainer, scmFBInterfaceSpec, paInstanceNameId, &scmInternalVars),
    var_Flag_nan_1(false_BOOL),
    var_Flag_nan_2(false_BOOL),
    var_Flag_nan_3(false_BOOL),
    var_Flag_pos_inf(false_BOOL),
    var_Flag_neg_inf(false_BOOL),
    var_In(0.0_REAL),
    var_ErrValue(0.0_REAL),
    var_Out(0.0_REAL),
    var_Err(false_BOOL),
    var_conn_Out(var_Out),
    var_conn_Err(var_Err),
    conn_CNF(this, 0),
    conn_In(nullptr),
    conn_ErrValue(nullptr),
    conn_Out(this, 0, &var_conn_Out),
    conn_Err(this, 1, &var_conn_Err) {
}

void FORTE_FbFilterNaN::setInitialValues() {
  var_Flag_nan_1 = false_BOOL;
  var_Flag_nan_2 = false_BOOL;
  var_Flag_nan_3 = false_BOOL;
  var_Flag_pos_inf = false_BOOL;
  var_Flag_neg_inf = false_BOOL;
  var_In = 0.0_REAL;
  var_ErrValue = 0.0_REAL;
  var_Out = 0.0_REAL;
  var_Err = false_BOOL;
}

void FORTE_FbFilterNaN::executeEvent(const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch(paEIID) {
    case scmEventREQID:
      enterStateREQ(paECET);
      break;
    default:
      break;
  }
}

void FORTE_FbFilterNaN::enterStateREQ(CEventChainExecutionThread *const paECET) {
  alg_REQ();
  sendOutputEvent(scmEventCNFID, paECET);
}

void FORTE_FbFilterNaN::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventREQID: {
      readData(0, var_In, conn_In);
      readData(1, var_ErrValue, conn_ErrValue);
      break;
    }
    default:
      break;
  }
}

void FORTE_FbFilterNaN::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventCNFID: {
      writeData(0, var_Out, conn_Out);
      writeData(1, var_Err, conn_Err);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_FbFilterNaN::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_In;
    case 1: return &var_ErrValue;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbFilterNaN::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_Out;
    case 1: return &var_Err;
  }
  return nullptr;
}

CEventConnection *FORTE_FbFilterNaN::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **FORTE_FbFilterNaN::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_In;
    case 1: return &conn_ErrValue;
  }
  return nullptr;
}

CDataConnection *FORTE_FbFilterNaN::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_Out;
    case 1: return &conn_Err;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbFilterNaN::getVarInternal(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_Flag_nan_1;
    case 1: return &var_Flag_nan_2;
    case 2: return &var_Flag_nan_3;
    case 3: return &var_Flag_pos_inf;
    case 4: return &var_Flag_neg_inf;
  }
  return nullptr;
}

void FORTE_FbFilterNaN::alg_REQ(void) {

  #line 5 "FbFilterNaN.fbt"
  var_Flag_nan_1 = func_EQ(func_AND<CIEC_DWORD>(func_REAL_TO_DWORD(var_In), 2139095040_DWORD), 2139095040_DWORD);
  #line 6 "FbFilterNaN.fbt"
  var_Flag_nan_2 = func_NE(var_In, var_In);
  #line 7 "FbFilterNaN.fbt"
  var_Flag_nan_3 = func_EQ(func_DIV<CIEC_REAL>(0.0_REAL, 0.0_REAL), var_In);
  #line 8 "FbFilterNaN.fbt"
  var_Flag_pos_inf = func_EQ(func_DIV<CIEC_REAL>(1.0_REAL, 0.0_REAL), var_In);
  #line 9 "FbFilterNaN.fbt"
  var_Flag_neg_inf = func_EQ(func_DIV<CIEC_REAL>(-1.0_REAL, 0.0_REAL), var_In);
  #line 11 "FbFilterNaN.fbt"
  var_Err = func_OR<CIEC_BOOL>(func_OR<CIEC_BOOL>(func_OR<CIEC_BOOL>(func_OR<CIEC_BOOL>(var_Flag_nan_1, var_Flag_nan_2), var_Flag_nan_3), var_Flag_pos_inf), var_Flag_neg_inf);
  #line 13 "FbFilterNaN.fbt"
  if (var_Err) {
    #line 14 "FbFilterNaN.fbt"
    var_Out = var_ErrValue;
  }
  else {
    #line 22 "FbFilterNaN.fbt"
    var_Out = var_In;
  }
}
