/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbAlarm
 *** Description: Блок предупреждений.
 *** Version:
 ***     2.2: 2026-03-20/VA - LIB_PLC -
 *************************************************************************/

#pragma once

#include "core/simplefb.h"
#include "core/datatypes/forte_bool.h"
#include "core/datatypes/forte_real.h"
#include "core/datatypes/forte_udint.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

class FORTE_FbAlarm final : public CSimpleFB {
  DECLARE_FIRMWARE_FB(FORTE_FbAlarm)

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

    CIEC_BOOL var__AlarmHi;
    CIEC_BOOL var__AlarmLo;
    CIEC_UDINT var_Timer1;
    CIEC_UDINT var_Timer2;

    CIEC_ANY *getVarInternal(size_t) override;

    void alg_REQ(void);

    void enterStateREQ(CEventChainExecutionThread *const paECET);

    void executeEvent(TEventID paEIID, CEventChainExecutionThread *const paECET) override;

    void readInputData(TEventID paEIID) override;
    void writeOutputData(TEventID paEIID) override;
    void setInitialValues() override;

  public:
    FORTE_FbAlarm(CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer);

    CIEC_REAL var_In;
    CIEC_REAL var_LevelHi;
    CIEC_REAL var_LevelLo;
    CIEC_UDINT var_TimeDelay;
    CIEC_UDINT var_Ts_ms;

    CIEC_BOOL var_AlarmHi;
    CIEC_BOOL var_AlarmLo;

    CIEC_BOOL var_conn_AlarmHi;
    CIEC_BOOL var_conn_AlarmLo;

    CEventConnection conn_CNF;

    CDataConnection *conn_In;
    CDataConnection *conn_LevelHi;
    CDataConnection *conn_LevelLo;
    CDataConnection *conn_TimeDelay;
    CDataConnection *conn_Ts_ms;

    CDataConnection conn_AlarmHi;
    CDataConnection conn_AlarmLo;

    CIEC_ANY *getDI(size_t) override;
    CIEC_ANY *getDO(size_t) override;
    CEventConnection *getEOConUnchecked(TPortId) override;
    CDataConnection **getDIConUnchecked(TPortId) override;
    CDataConnection *getDOConUnchecked(TPortId) override;

    void evt_REQ(const CIEC_REAL &paIn, const CIEC_REAL &paLevelHi, const CIEC_REAL &paLevelLo, const CIEC_UDINT &paTimeDelay, const CIEC_UDINT &paTs_ms, CIEC_BOOL &paAlarmHi, CIEC_BOOL &paAlarmLo) {
      var_In = paIn;
      var_LevelHi = paLevelHi;
      var_LevelLo = paLevelLo;
      var_TimeDelay = paTimeDelay;
      var_Ts_ms = paTs_ms;
      executeEvent(scmEventREQID, nullptr);
      paAlarmHi = var_AlarmHi;
      paAlarmLo = var_AlarmLo;
    }

    void operator()(const CIEC_REAL &paIn, const CIEC_REAL &paLevelHi, const CIEC_REAL &paLevelLo, const CIEC_UDINT &paTimeDelay, const CIEC_UDINT &paTs_ms, CIEC_BOOL &paAlarmHi, CIEC_BOOL &paAlarmLo) {
      evt_REQ(paIn, paLevelHi, paLevelLo, paTimeDelay, paTs_ms, paAlarmHi, paAlarmLo);
    }
};

