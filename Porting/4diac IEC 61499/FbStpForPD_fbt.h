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

#pragma once

#include "core/simplefb.h"
#include "core/datatypes/forte_bool.h"
#include "core/datatypes/forte_real.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

class FORTE_FbStpForPD final : public CSimpleFB {
  DECLARE_FIRMWARE_FB(FORTE_FbStpForPD)

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

    CIEC_REAL var_Pos;
    CIEC_REAL var_Vin;
    CIEC_REAL var_Vopen;
    CIEC_REAL var_Vclose;
    CIEC_REAL var_SopenMin;
    CIEC_REAL var_ScloseMin;

    CIEC_ANY *getVarInternal(size_t) override;

    void alg_REQ(void);

    void enterStateREQ(CEventChainExecutionThread *const paECET);

    void executeEvent(TEventID paEIID, CEventChainExecutionThread *const paECET) override;

    void readInputData(TEventID paEIID) override;
    void writeOutputData(TEventID paEIID) override;
    void setInitialValues() override;

  public:
    FORTE_FbStpForPD(CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer);

    CIEC_REAL var_InFromPD;
    CIEC_REAL var_TimeOpen;
    CIEC_REAL var_TimeClose;
    CIEC_REAL var_TimeMin;
    CIEC_REAL var_Smax;
    CIEC_REAL var_Smin;
    CIEC_BOOL var_SensorOpen;
    CIEC_BOOL var_SensorClose;
    CIEC_REAL var_Ts;
    CIEC_BOOL var_Reset;

    CIEC_BOOL var_CmdOpen;
    CIEC_BOOL var_CmdClose;

    CIEC_BOOL var_conn_CmdOpen;
    CIEC_BOOL var_conn_CmdClose;

    CEventConnection conn_CNF;

    CDataConnection *conn_InFromPD;
    CDataConnection *conn_TimeOpen;
    CDataConnection *conn_TimeClose;
    CDataConnection *conn_TimeMin;
    CDataConnection *conn_Smax;
    CDataConnection *conn_Smin;
    CDataConnection *conn_SensorOpen;
    CDataConnection *conn_SensorClose;
    CDataConnection *conn_Ts;
    CDataConnection *conn_Reset;

    CDataConnection conn_CmdOpen;
    CDataConnection conn_CmdClose;

    CIEC_ANY *getDI(size_t) override;
    CIEC_ANY *getDO(size_t) override;
    CEventConnection *getEOConUnchecked(TPortId) override;
    CDataConnection **getDIConUnchecked(TPortId) override;
    CDataConnection *getDOConUnchecked(TPortId) override;

    void evt_REQ(const CIEC_REAL &paInFromPD, const CIEC_REAL &paTimeOpen, const CIEC_REAL &paTimeClose, const CIEC_REAL &paTimeMin, const CIEC_REAL &paSmax, const CIEC_REAL &paSmin, const CIEC_BOOL &paSensorOpen, const CIEC_BOOL &paSensorClose, const CIEC_REAL &paTs, const CIEC_BOOL &paReset, CIEC_BOOL &paCmdOpen, CIEC_BOOL &paCmdClose) {
      var_InFromPD = paInFromPD;
      var_TimeOpen = paTimeOpen;
      var_TimeClose = paTimeClose;
      var_TimeMin = paTimeMin;
      var_Smax = paSmax;
      var_Smin = paSmin;
      var_SensorOpen = paSensorOpen;
      var_SensorClose = paSensorClose;
      var_Ts = paTs;
      var_Reset = paReset;
      executeEvent(scmEventREQID, nullptr);
      paCmdOpen = var_CmdOpen;
      paCmdClose = var_CmdClose;
    }

    void operator()(const CIEC_REAL &paInFromPD, const CIEC_REAL &paTimeOpen, const CIEC_REAL &paTimeClose, const CIEC_REAL &paTimeMin, const CIEC_REAL &paSmax, const CIEC_REAL &paSmin, const CIEC_BOOL &paSensorOpen, const CIEC_BOOL &paSensorClose, const CIEC_REAL &paTs, const CIEC_BOOL &paReset, CIEC_BOOL &paCmdOpen, CIEC_BOOL &paCmdClose) {
      evt_REQ(paInFromPD, paTimeOpen, paTimeClose, paTimeMin, paSmax, paSmin, paSensorOpen, paSensorClose, paTs, paReset, paCmdOpen, paCmdClose);
    }
};

