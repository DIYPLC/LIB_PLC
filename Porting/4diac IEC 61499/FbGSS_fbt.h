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

#pragma once

#include "core/simplefb.h"
#include "core/datatypes/forte_bool.h"
#include "core/datatypes/forte_dint.h"
#include "core/datatypes/forte_dword.h"
#include "core/datatypes/forte_real.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

class FORTE_FbGSS final : public CSimpleFB {
  DECLARE_FIRMWARE_FB(FORTE_FbGSS)

  private:
    static const CStringDictionary::TStringId scmDataInputNames[];
    static const CStringDictionary::TStringId scmDataInputTypeIds[];
    static const CStringDictionary::TStringId scmDataOutputNames[];
    static const CStringDictionary::TStringId scmDataOutputTypeIds[];
    static const TEventID scmEventREQID = 0;
    static const TDataIOID scmEIWith[];
    static const TForteInt16 scmEIWithIndexes[];
    static const CStringDictionary::TStringId scmEventInputNames[];
    static const TEventID scmEventCNFID = 0;
    static const TDataIOID scmEOWith[];
    static const TForteInt16 scmEOWithIndexes[];
    static const CStringDictionary::TStringId scmEventOutputNames[];

    static const SFBInterfaceSpec scmFBInterfaceSpec;

    static const CStringDictionary::TStringId scmInternalsNames[];
    static const CStringDictionary::TStringId scmInternalsTypeIds[];
    static const SInternalVarsInformation scmInternalVars;

    CIEC_REAL var_CurrentTime;
    CIEC_REAL var_IntegratorTriangle;
    CIEC_DINT var_SummatorRnd;
    CIEC_DWORD var_Tmp;

    static const CIEC_REAL var_const_PI;

    CIEC_ANY *getVarInternal(size_t) override;

    void alg_REQ(void);

    void enterStateREQ(CEventChainExecutionThread *const paECET);

    void executeEvent(TEventID paEIID, CEventChainExecutionThread *const paECET) override;

    void readInputData(TEventID paEIID) override;
    void writeOutputData(TEventID paEIID) override;
    void setInitialValues() override;

  public:
    FORTE_FbGSS(CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer);

    CIEC_REAL var_Amplitude;
    CIEC_REAL var_Period;
    CIEC_REAL var_Phase;
    CIEC_REAL var_Offset;
    CIEC_REAL var_PulseTime;
    CIEC_REAL var_Ts;

    CIEC_REAL var_Sine;
    CIEC_REAL var_Cosine;
    CIEC_REAL var_RectangleR;
    CIEC_BOOL var_RectangleB;
    CIEC_REAL var_Triangle;
    CIEC_REAL var_Prnd;

    CIEC_REAL var_conn_Sine;
    CIEC_REAL var_conn_Cosine;
    CIEC_REAL var_conn_RectangleR;
    CIEC_BOOL var_conn_RectangleB;
    CIEC_REAL var_conn_Triangle;
    CIEC_REAL var_conn_Prnd;

    CEventConnection conn_CNF;

    CDataConnection *conn_Amplitude;
    CDataConnection *conn_Period;
    CDataConnection *conn_Phase;
    CDataConnection *conn_Offset;
    CDataConnection *conn_PulseTime;
    CDataConnection *conn_Ts;

    CDataConnection conn_Sine;
    CDataConnection conn_Cosine;
    CDataConnection conn_RectangleR;
    CDataConnection conn_RectangleB;
    CDataConnection conn_Triangle;
    CDataConnection conn_Prnd;

    CIEC_ANY *getDI(size_t) override;
    CIEC_ANY *getDO(size_t) override;
    CEventConnection *getEOConUnchecked(TPortId) override;
    CDataConnection **getDIConUnchecked(TPortId) override;
    CDataConnection *getDOConUnchecked(TPortId) override;

    void evt_REQ(const CIEC_REAL &paAmplitude, const CIEC_REAL &paPeriod, const CIEC_REAL &paPhase, const CIEC_REAL &paOffset, const CIEC_REAL &paPulseTime, const CIEC_REAL &paTs, CIEC_REAL &paSine, CIEC_REAL &paCosine, CIEC_REAL &paRectangleR, CIEC_BOOL &paRectangleB, CIEC_REAL &paTriangle, CIEC_REAL &paPrnd) {
      var_Amplitude = paAmplitude;
      var_Period = paPeriod;
      var_Phase = paPhase;
      var_Offset = paOffset;
      var_PulseTime = paPulseTime;
      var_Ts = paTs;
      executeEvent(scmEventREQID, nullptr);
      paSine = var_Sine;
      paCosine = var_Cosine;
      paRectangleR = var_RectangleR;
      paRectangleB = var_RectangleB;
      paTriangle = var_Triangle;
      paPrnd = var_Prnd;
    }

    void operator()(const CIEC_REAL &paAmplitude, const CIEC_REAL &paPeriod, const CIEC_REAL &paPhase, const CIEC_REAL &paOffset, const CIEC_REAL &paPulseTime, const CIEC_REAL &paTs, CIEC_REAL &paSine, CIEC_REAL &paCosine, CIEC_REAL &paRectangleR, CIEC_BOOL &paRectangleB, CIEC_REAL &paTriangle, CIEC_REAL &paPrnd) {
      evt_REQ(paAmplitude, paPeriod, paPhase, paOffset, paPulseTime, paTs, paSine, paCosine, paRectangleR, paRectangleB, paTriangle, paPrnd);
    }
};

