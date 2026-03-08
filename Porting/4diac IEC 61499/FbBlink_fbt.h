/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbBlink
 *** Description: Мигающий светодиод.
 *** Version:
 ***     1.2: 2026-03-08/VA - LIB_PLC -
 *************************************************************************/

#pragma once

#include "core/simplefb.h"
#include "core/datatypes/forte_bool.h"
#include "core/datatypes/forte_udint.h"
#include "core/datatypes/forte_uint.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

class FORTE_FbBlink final : public CSimpleFB {
  DECLARE_FIRMWARE_FB(FORTE_FbBlink)

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

    CIEC_UDINT var_Timer1;
    CIEC_UINT var_State1;

    static const CIEC_UINT var_const_STATE_RESET;
    static const CIEC_UINT var_const_STATE_ON;
    static const CIEC_UINT var_const_STATE_OFF;

    CIEC_ANY *getVarInternal(size_t) override;

    void alg_REQ(void);

    void enterStateREQ(CEventChainExecutionThread *const paECET);

    void executeEvent(TEventID paEIID, CEventChainExecutionThread *const paECET) override;

    void readInputData(TEventID paEIID) override;
    void writeOutputData(TEventID paEIID) override;
    void setInitialValues() override;

  public:
    FORTE_FbBlink(CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer);

    CIEC_UDINT var_TimeOn;
    CIEC_UDINT var_TimeOff;
    CIEC_UDINT var_Ts_ms;
    CIEC_BOOL var_Reset;

    CIEC_BOOL var_BlinkLamp;

    CIEC_BOOL var_conn_BlinkLamp;

    CEventConnection conn_CNF;

    CDataConnection *conn_TimeOn;
    CDataConnection *conn_TimeOff;
    CDataConnection *conn_Ts_ms;
    CDataConnection *conn_Reset;

    CDataConnection conn_BlinkLamp;

    CIEC_ANY *getDI(size_t) override;
    CIEC_ANY *getDO(size_t) override;
    CEventConnection *getEOConUnchecked(TPortId) override;
    CDataConnection **getDIConUnchecked(TPortId) override;
    CDataConnection *getDOConUnchecked(TPortId) override;

    void evt_REQ(const CIEC_UDINT &paTimeOn, const CIEC_UDINT &paTimeOff, const CIEC_UDINT &paTs_ms, const CIEC_BOOL &paReset, CIEC_BOOL &paBlinkLamp) {
      var_TimeOn = paTimeOn;
      var_TimeOff = paTimeOff;
      var_Ts_ms = paTs_ms;
      var_Reset = paReset;
      executeEvent(scmEventREQID, nullptr);
      paBlinkLamp = var_BlinkLamp;
    }

    void operator()(const CIEC_UDINT &paTimeOn, const CIEC_UDINT &paTimeOff, const CIEC_UDINT &paTs_ms, const CIEC_BOOL &paReset, CIEC_BOOL &paBlinkLamp) {
      evt_REQ(paTimeOn, paTimeOff, paTs_ms, paReset, paBlinkLamp);
    }
};

