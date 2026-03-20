/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbModeSelector
 *** Description: Переключатель режимов работы.
 *** Version:
 ***     2.1: 2026-03-20/VA - LIB_PLC -
 *************************************************************************/

#pragma once

#include "core/simplefb.h"
#include "core/datatypes/forte_bool.h"
#include "core/datatypes/forte_uint.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

class FORTE_FbModeSelector final : public CSimpleFB {
  DECLARE_FIRMWARE_FB(FORTE_FbModeSelector)

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

    CIEC_UINT var_State1;
    CIEC_BOOL var_FlagError;

    static const CIEC_UINT var_const_STATE_STOP;
    static const CIEC_UINT var_const_STATE_MANUAL;
    static const CIEC_UINT var_const_STATE_AUTO;

    CIEC_ANY *getVarInternal(size_t) override;

    void alg_REQ(void);

    void enterStateREQ(CEventChainExecutionThread *const paECET);

    void executeEvent(TEventID paEIID, CEventChainExecutionThread *const paECET) override;

    void readInputData(TEventID paEIID) override;
    void writeOutputData(TEventID paEIID) override;
    void setInitialValues() override;

  public:
    FORTE_FbModeSelector(CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer);

    CIEC_BOOL var_ButtonStop;
    CIEC_BOOL var_ButtonManual;
    CIEC_BOOL var_ButtonAuto;
    CIEC_BOOL var_Error;
    CIEC_BOOL var_Reset;

    CIEC_BOOL var_LampStop;
    CIEC_BOOL var_LampManual;
    CIEC_BOOL var_LampAuto;

    CIEC_BOOL var_conn_LampStop;
    CIEC_BOOL var_conn_LampManual;
    CIEC_BOOL var_conn_LampAuto;

    CEventConnection conn_CNF;

    CDataConnection *conn_ButtonStop;
    CDataConnection *conn_ButtonManual;
    CDataConnection *conn_ButtonAuto;
    CDataConnection *conn_Error;
    CDataConnection *conn_Reset;

    CDataConnection conn_LampStop;
    CDataConnection conn_LampManual;
    CDataConnection conn_LampAuto;

    CIEC_ANY *getDI(size_t) override;
    CIEC_ANY *getDO(size_t) override;
    CEventConnection *getEOConUnchecked(TPortId) override;
    CDataConnection **getDIConUnchecked(TPortId) override;
    CDataConnection *getDOConUnchecked(TPortId) override;

    void evt_REQ(const CIEC_BOOL &paButtonStop, const CIEC_BOOL &paButtonManual, const CIEC_BOOL &paButtonAuto, const CIEC_BOOL &paError, const CIEC_BOOL &paReset, CIEC_BOOL &paLampStop, CIEC_BOOL &paLampManual, CIEC_BOOL &paLampAuto) {
      var_ButtonStop = paButtonStop;
      var_ButtonManual = paButtonManual;
      var_ButtonAuto = paButtonAuto;
      var_Error = paError;
      var_Reset = paReset;
      executeEvent(scmEventREQID, nullptr);
      paLampStop = var_LampStop;
      paLampManual = var_LampManual;
      paLampAuto = var_LampAuto;
    }

    void operator()(const CIEC_BOOL &paButtonStop, const CIEC_BOOL &paButtonManual, const CIEC_BOOL &paButtonAuto, const CIEC_BOOL &paError, const CIEC_BOOL &paReset, CIEC_BOOL &paLampStop, CIEC_BOOL &paLampManual, CIEC_BOOL &paLampAuto) {
      evt_REQ(paButtonStop, paButtonManual, paButtonAuto, paError, paReset, paLampStop, paLampManual, paLampAuto);
    }
};

