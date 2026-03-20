/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbGSS
 *** Description: Генератор сигналов и псевдослучайных чисел.
 *** Version:
 ***     2.1: 2026-03-20/VA - LIB_PLC -
 *************************************************************************/

#include "FbGSS_fbt.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FbGSS_fbt_gen.cpp"
#endif

#include "core/datatypes/forte_bool.h"
#include "core/datatypes/forte_dint.h"
#include "core/datatypes/forte_dword.h"
#include "core/datatypes/forte_real.h"
#include "core/datatypes/forte_sint.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

DEFINE_FIRMWARE_FB(FORTE_FbGSS, g_nStringIdFbGSS)

const CStringDictionary::TStringId FORTE_FbGSS::scmDataInputNames[] = {g_nStringIdAmplitude, g_nStringIdPeriod, g_nStringIdPhase, g_nStringIdOffset, g_nStringIdPulseTime, g_nStringIdTs};
const CStringDictionary::TStringId FORTE_FbGSS::scmDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};
const CStringDictionary::TStringId FORTE_FbGSS::scmDataOutputNames[] = {g_nStringIdSine, g_nStringIdCosine, g_nStringIdRectangleR, g_nStringIdRectangleB, g_nStringIdTriangle, g_nStringIdPrnd};
const CStringDictionary::TStringId FORTE_FbGSS::scmDataOutputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdBOOL, g_nStringIdREAL, g_nStringIdREAL};
const TDataIOID FORTE_FbGSS::scmEIWith[] = {0, 1, 2, 3, 4, 5, scmWithListDelimiter};
const TForteInt16 FORTE_FbGSS::scmEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbGSS::scmEventInputNames[] = {g_nStringIdREQ};
const TDataIOID FORTE_FbGSS::scmEOWith[] = {0, 1, 2, 3, 4, 5, scmWithListDelimiter};
const TForteInt16 FORTE_FbGSS::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbGSS::scmEventOutputNames[] = {g_nStringIdCNF};
const SFBInterfaceSpec FORTE_FbGSS::scmFBInterfaceSpec = {
  1, scmEventInputNames, nullptr, scmEIWith, scmEIWithIndexes,
  1, scmEventOutputNames, nullptr, scmEOWith, scmEOWithIndexes,
  6, scmDataInputNames, scmDataInputTypeIds,
  6, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

const CStringDictionary::TStringId FORTE_FbGSS::scmInternalsNames[] = {g_nStringIdCurrentTime, g_nStringIdIntegratorTriangle, g_nStringIdSummatorRnd, g_nStringIdTmp};
const CStringDictionary::TStringId FORTE_FbGSS::scmInternalsTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdDINT, g_nStringIdDWORD};
const SInternalVarsInformation FORTE_FbGSS::scmInternalVars = {4, scmInternalsNames, scmInternalsTypeIds};

const CIEC_REAL FORTE_FbGSS::var_const_PI = 3.14159265358979323846_REAL;


FORTE_FbGSS::FORTE_FbGSS(const CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer) :
    CSimpleFB(paContainer, scmFBInterfaceSpec, paInstanceNameId, &scmInternalVars),
    var_CurrentTime(0.0_REAL),
    var_IntegratorTriangle(0.0_REAL),
    var_SummatorRnd(1_DINT),
    var_Tmp(0_DWORD),
    var_Amplitude(1.0_REAL),
    var_Period(10.0_REAL),
    var_Phase(0.0_REAL),
    var_Offset(0.0_REAL),
    var_PulseTime(5.0_REAL),
    var_Ts(0.1_REAL),
    var_Sine(0.0_REAL),
    var_Cosine(0.0_REAL),
    var_RectangleR(0.0_REAL),
    var_RectangleB(false_BOOL),
    var_Triangle(0.0_REAL),
    var_Prnd(0.0_REAL),
    var_conn_Sine(var_Sine),
    var_conn_Cosine(var_Cosine),
    var_conn_RectangleR(var_RectangleR),
    var_conn_RectangleB(var_RectangleB),
    var_conn_Triangle(var_Triangle),
    var_conn_Prnd(var_Prnd),
    conn_CNF(this, 0),
    conn_Amplitude(nullptr),
    conn_Period(nullptr),
    conn_Phase(nullptr),
    conn_Offset(nullptr),
    conn_PulseTime(nullptr),
    conn_Ts(nullptr),
    conn_Sine(this, 0, &var_conn_Sine),
    conn_Cosine(this, 1, &var_conn_Cosine),
    conn_RectangleR(this, 2, &var_conn_RectangleR),
    conn_RectangleB(this, 3, &var_conn_RectangleB),
    conn_Triangle(this, 4, &var_conn_Triangle),
    conn_Prnd(this, 5, &var_conn_Prnd) {
}

void FORTE_FbGSS::setInitialValues() {
  var_CurrentTime = 0.0_REAL;
  var_IntegratorTriangle = 0.0_REAL;
  var_SummatorRnd = 1_DINT;
  var_Tmp = 0_DWORD;
  var_Amplitude = 1.0_REAL;
  var_Period = 10.0_REAL;
  var_Phase = 0.0_REAL;
  var_Offset = 0.0_REAL;
  var_PulseTime = 5.0_REAL;
  var_Ts = 0.1_REAL;
  var_Sine = 0.0_REAL;
  var_Cosine = 0.0_REAL;
  var_RectangleR = 0.0_REAL;
  var_RectangleB = false_BOOL;
  var_Triangle = 0.0_REAL;
  var_Prnd = 0.0_REAL;
}

void FORTE_FbGSS::executeEvent(const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch(paEIID) {
    case scmEventREQID:
      enterStateREQ(paECET);
      break;
    default:
      break;
  }
}

void FORTE_FbGSS::enterStateREQ(CEventChainExecutionThread *const paECET) {
  alg_REQ();
  sendOutputEvent(scmEventCNFID, paECET);
}

void FORTE_FbGSS::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventREQID: {
      readData(0, var_Amplitude, conn_Amplitude);
      readData(1, var_Period, conn_Period);
      readData(2, var_Phase, conn_Phase);
      readData(3, var_Offset, conn_Offset);
      readData(4, var_PulseTime, conn_PulseTime);
      readData(5, var_Ts, conn_Ts);
      break;
    }
    default:
      break;
  }
}

void FORTE_FbGSS::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventCNFID: {
      writeData(0, var_Sine, conn_Sine);
      writeData(1, var_Cosine, conn_Cosine);
      writeData(2, var_RectangleR, conn_RectangleR);
      writeData(3, var_RectangleB, conn_RectangleB);
      writeData(4, var_Triangle, conn_Triangle);
      writeData(5, var_Prnd, conn_Prnd);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_FbGSS::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_Amplitude;
    case 1: return &var_Period;
    case 2: return &var_Phase;
    case 3: return &var_Offset;
    case 4: return &var_PulseTime;
    case 5: return &var_Ts;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbGSS::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_Sine;
    case 1: return &var_Cosine;
    case 2: return &var_RectangleR;
    case 3: return &var_RectangleB;
    case 4: return &var_Triangle;
    case 5: return &var_Prnd;
  }
  return nullptr;
}

CEventConnection *FORTE_FbGSS::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **FORTE_FbGSS::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_Amplitude;
    case 1: return &conn_Period;
    case 2: return &conn_Phase;
    case 3: return &conn_Offset;
    case 4: return &conn_PulseTime;
    case 5: return &conn_Ts;
  }
  return nullptr;
}

CDataConnection *FORTE_FbGSS::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_Sine;
    case 1: return &conn_Cosine;
    case 2: return &conn_RectangleR;
    case 3: return &conn_RectangleB;
    case 4: return &conn_Triangle;
    case 5: return &conn_Prnd;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbGSS::getVarInternal(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_CurrentTime;
    case 1: return &var_IntegratorTriangle;
    case 2: return &var_SummatorRnd;
    case 3: return &var_Tmp;
  }
  return nullptr;
}

void FORTE_FbGSS::alg_REQ(void) {

  #line 2 "FbGSS.fbt"
  var_Sine = func_ADD<CIEC_REAL>(func_MUL<CIEC_REAL>(var_Amplitude, func_SIN(func_ADD<CIEC_REAL>(func_MUL<CIEC_REAL>(func_MUL<CIEC_REAL>(func_MUL<CIEC_REAL>(2.0_REAL, var_const_PI), func_DIV<CIEC_REAL>(1.0_REAL, var_Period)), var_CurrentTime), var_Phase))), var_Offset);
  #line 3 "FbGSS.fbt"
  var_Cosine = func_ADD<CIEC_REAL>(func_MUL<CIEC_REAL>(var_Amplitude, func_COS(func_ADD<CIEC_REAL>(func_MUL<CIEC_REAL>(func_MUL<CIEC_REAL>(func_MUL<CIEC_REAL>(2.0_REAL, var_const_PI), func_DIV<CIEC_REAL>(1.0_REAL, var_Period)), var_CurrentTime), var_Phase))), var_Offset);
  #line 5 "FbGSS.fbt"
  if (func_LT(var_CurrentTime, var_PulseTime)) {
    #line 6 "FbGSS.fbt"
    var_RectangleR = func_ADD<CIEC_REAL>(var_Amplitude, var_Offset);
    #line 7 "FbGSS.fbt"
    var_RectangleB = true_BOOL;
  }
  else {
    #line 9 "FbGSS.fbt"
    var_RectangleR = var_Offset;
    #line 10 "FbGSS.fbt"
    var_RectangleB = false_BOOL;
  }
  #line 13 "FbGSS.fbt"
  if (func_LE(var_CurrentTime, func_MUL<CIEC_REAL>(var_Period, 0.5_REAL))) {
    #line 14 "FbGSS.fbt"
    var_IntegratorTriangle = func_ADD<CIEC_REAL>(var_IntegratorTriangle, var_Ts);
  }
  else {
    #line 16 "FbGSS.fbt"
    var_IntegratorTriangle = func_SUB<CIEC_REAL>(var_IntegratorTriangle, var_Ts);
  }
  #line 18 "FbGSS.fbt"
  if (func_NE(var_Period, 0.0_REAL)) {
    #line 19 "FbGSS.fbt"
    var_Triangle = func_ADD<CIEC_REAL>(func_MUL<CIEC_REAL>(func_DIV<CIEC_REAL>(func_MUL<CIEC_REAL>(var_IntegratorTriangle, 2.0_REAL), var_Period), var_Amplitude), var_Offset);
  }
  #line 23 "FbGSS.fbt"
  var_SummatorRnd = func_ADD<CIEC_DINT>(func_MUL<CIEC_DINT>(var_SummatorRnd, 1103515245_DINT), 12345_DINT);
  #line 25 "FbGSS.fbt"
  var_Tmp = func_AND<CIEC_DWORD>(func_DINT_TO_DWORD(var_SummatorRnd), 2147418112_DWORD);
  #line 27 "FbGSS.fbt"
  var_Tmp = func_SHR(var_Tmp, 16_SINT);
  #line 29 "FbGSS.fbt"
  var_Prnd = func_ADD<CIEC_REAL>(func_MUL<CIEC_REAL>(func_DIV<CIEC_REAL>(func_DINT_TO_REAL(func_DWORD_TO_DINT(var_Tmp)), 32767.0_REAL), var_Amplitude), var_Offset);
  #line 31 "FbGSS.fbt"
  var_CurrentTime = func_ADD<CIEC_REAL>(var_CurrentTime, var_Ts);
  #line 32 "FbGSS.fbt"
  if (func_GE(var_CurrentTime, var_Period)) {
    #line 33 "FbGSS.fbt"
    var_CurrentTime = 0.0_REAL;
    #line 34 "FbGSS.fbt"
    var_IntegratorTriangle = 0.0_REAL;
  }
}
