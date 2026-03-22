/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbValve
 *** Description: Пневмоцилиндр с концевиками.
 *** Version:
 ***     2.3: 2026-03-20/VA - LIB_PLC -
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

class FORTE_FbValve final : public CSimpleFB {
  DECLARE_FIRMWARE_FB(FORTE_FbValve)

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
    static const CIEC_UINT var_const_STATE_VALVE_CLOSING;
    static const CIEC_UINT var_const_STATE_VALVE_CLOSE;
    static const CIEC_UINT var_const_STATE_VALVE_OPENING;
    static const CIEC_UINT var_const_STATE_VALVE_OPEN;
    static const CIEC_UINT var_const_STATE_ERROR_CLOSE;
    static const CIEC_UINT var_const_STATE_ERROR_OPEN;

    CIEC_ANY *getVarInternal(size_t) override;

    void alg_REQ(void);

    void enterStateREQ(CEventChainExecutionThread *const paECET);

    void executeEvent(TEventID paEIID, CEventChainExecutionThread *const paECET) override;

    void readInputData(TEventID paEIID) override;
    void writeOutputData(TEventID paEIID) override;
    void setInitialValues() override;

  public:
    FORTE_FbValve(CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer);

    CIEC_BOOL var_CommandOpen;
    CIEC_BOOL var_FeedbackOpen;
    CIEC_BOOL var_FeedbackClose;
    CIEC_BOOL var_OnFeedbackOpen;
    CIEC_BOOL var_OnFeedbackClose;
    CIEC_BOOL var_Reset;
    CIEC_UDINT var_TimeOpen;
    CIEC_UDINT var_TimeClose;
    CIEC_UDINT var_Ts_ms;

    CIEC_BOOL var_CoilOpen;
    CIEC_BOOL var_StateOpen;
    CIEC_BOOL var_StateClose;
    CIEC_BOOL var_Error;

    CIEC_BOOL var_conn_CoilOpen;
    CIEC_BOOL var_conn_StateOpen;
    CIEC_BOOL var_conn_StateClose;
    CIEC_BOOL var_conn_Error;

    CEventConnection conn_CNF;

    CDataConnection *conn_CommandOpen;
    CDataConnection *conn_FeedbackOpen;
    CDataConnection *conn_FeedbackClose;
    CDataConnection *conn_OnFeedbackOpen;
    CDataConnection *conn_OnFeedbackClose;
    CDataConnection *conn_Reset;
    CDataConnection *conn_TimeOpen;
    CDataConnection *conn_TimeClose;
    CDataConnection *conn_Ts_ms;

    CDataConnection conn_CoilOpen;
    CDataConnection conn_StateOpen;
    CDataConnection conn_StateClose;
    CDataConnection conn_Error;

    CIEC_ANY *getDI(size_t) override;
    CIEC_ANY *getDO(size_t) override;
    CEventConnection *getEOConUnchecked(TPortId) override;
    CDataConnection **getDIConUnchecked(TPortId) override;
    CDataConnection *getDOConUnchecked(TPortId) override;

    void evt_REQ(const CIEC_BOOL &paCommandOpen, const CIEC_BOOL &paFeedbackOpen, const CIEC_BOOL &paFeedbackClose, const CIEC_BOOL &paOnFeedbackOpen, const CIEC_BOOL &paOnFeedbackClose, const CIEC_BOOL &paReset, const CIEC_UDINT &paTimeOpen, const CIEC_UDINT &paTimeClose, const CIEC_UDINT &paTs_ms, CIEC_BOOL &paCoilOpen, CIEC_BOOL &paStateOpen, CIEC_BOOL &paStateClose, CIEC_BOOL &paError) {
      var_CommandOpen = paCommandOpen;
      var_FeedbackOpen = paFeedbackOpen;
      var_FeedbackClose = paFeedbackClose;
      var_OnFeedbackOpen = paOnFeedbackOpen;
      var_OnFeedbackClose = paOnFeedbackClose;
      var_Reset = paReset;
      var_TimeOpen = paTimeOpen;
      var_TimeClose = paTimeClose;
      var_Ts_ms = paTs_ms;
      executeEvent(scmEventREQID, nullptr);
      paCoilOpen = var_CoilOpen;
      paStateOpen = var_StateOpen;
      paStateClose = var_StateClose;
      paError = var_Error;
    }

    void operator()(const CIEC_BOOL &paCommandOpen, const CIEC_BOOL &paFeedbackOpen, const CIEC_BOOL &paFeedbackClose, const CIEC_BOOL &paOnFeedbackOpen, const CIEC_BOOL &paOnFeedbackClose, const CIEC_BOOL &paReset, const CIEC_UDINT &paTimeOpen, const CIEC_UDINT &paTimeClose, const CIEC_UDINT &paTs_ms, CIEC_BOOL &paCoilOpen, CIEC_BOOL &paStateOpen, CIEC_BOOL &paStateClose, CIEC_BOOL &paError) {
      evt_REQ(paCommandOpen, paFeedbackOpen, paFeedbackClose, paOnFeedbackOpen, paOnFeedbackClose, paReset, paTimeOpen, paTimeClose, paTs_ms, paCoilOpen, paStateOpen, paStateClose, paError);
    }
};

