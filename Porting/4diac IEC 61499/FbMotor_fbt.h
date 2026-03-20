/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbMotor
 *** Description: Двигатель с частотником и контактором.
 *** Version:
 ***     2.1: 2026-03-20/VA - LIB_PLC -
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

class FORTE_FbMotor final : public CSimpleFB {
  DECLARE_FIRMWARE_FB(FORTE_FbMotor)

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
    CIEC_UDINT var_Timer1;
    CIEC_UDINT var_Timer2;

    static const CIEC_UINT var_const_STATE_STOP;
    static const CIEC_UINT var_const_STATE_CONTACTOR_ON;
    static const CIEC_UINT var_const_STATE_DRIVE_ON;
    static const CIEC_UINT var_const_STATE_RUN;
    static const CIEC_UINT var_const_STATE_DRIVE_OFF;
    static const CIEC_UINT var_const_STATE_CONTACTOR_OFF;

    CIEC_ANY *getVarInternal(size_t) override;

    void alg_REQ(void);

    void enterStateREQ(CEventChainExecutionThread *const paECET);

    void executeEvent(TEventID paEIID, CEventChainExecutionThread *const paECET) override;

    void readInputData(TEventID paEIID) override;
    void writeOutputData(TEventID paEIID) override;
    void setInitialValues() override;

  public:
    FORTE_FbMotor(CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer);

    CIEC_BOOL var_MotorRun;
    CIEC_BOOL var_VoltageOk;
    CIEC_BOOL var_DriveOk;
    CIEC_BOOL var_ContactorOk;
    CIEC_UDINT var_TimeMonitoring;
    CIEC_UDINT var_TimeDelayOn;
    CIEC_UDINT var_TimeDelayOff;
    CIEC_UDINT var_Ts_ms;
    CIEC_BOOL var_Reset;

    CIEC_BOOL var_MotorOn;
    CIEC_BOOL var_ContactorOn;
    CIEC_BOOL var_ErrorVoltage;
    CIEC_BOOL var_ErrorDrive;
    CIEC_BOOL var_ErrorContactor;

    CIEC_BOOL var_conn_MotorOn;
    CIEC_BOOL var_conn_ContactorOn;
    CIEC_BOOL var_conn_ErrorVoltage;
    CIEC_BOOL var_conn_ErrorDrive;
    CIEC_BOOL var_conn_ErrorContactor;

    CEventConnection conn_CNF;

    CDataConnection *conn_MotorRun;
    CDataConnection *conn_VoltageOk;
    CDataConnection *conn_DriveOk;
    CDataConnection *conn_ContactorOk;
    CDataConnection *conn_TimeMonitoring;
    CDataConnection *conn_TimeDelayOn;
    CDataConnection *conn_TimeDelayOff;
    CDataConnection *conn_Ts_ms;
    CDataConnection *conn_Reset;

    CDataConnection conn_MotorOn;
    CDataConnection conn_ContactorOn;
    CDataConnection conn_ErrorVoltage;
    CDataConnection conn_ErrorDrive;
    CDataConnection conn_ErrorContactor;

    CIEC_ANY *getDI(size_t) override;
    CIEC_ANY *getDO(size_t) override;
    CEventConnection *getEOConUnchecked(TPortId) override;
    CDataConnection **getDIConUnchecked(TPortId) override;
    CDataConnection *getDOConUnchecked(TPortId) override;

    void evt_REQ(const CIEC_BOOL &paMotorRun, const CIEC_BOOL &paVoltageOk, const CIEC_BOOL &paDriveOk, const CIEC_BOOL &paContactorOk, const CIEC_UDINT &paTimeMonitoring, const CIEC_UDINT &paTimeDelayOn, const CIEC_UDINT &paTimeDelayOff, const CIEC_UDINT &paTs_ms, const CIEC_BOOL &paReset, CIEC_BOOL &paMotorOn, CIEC_BOOL &paContactorOn, CIEC_BOOL &paErrorVoltage, CIEC_BOOL &paErrorDrive, CIEC_BOOL &paErrorContactor) {
      var_MotorRun = paMotorRun;
      var_VoltageOk = paVoltageOk;
      var_DriveOk = paDriveOk;
      var_ContactorOk = paContactorOk;
      var_TimeMonitoring = paTimeMonitoring;
      var_TimeDelayOn = paTimeDelayOn;
      var_TimeDelayOff = paTimeDelayOff;
      var_Ts_ms = paTs_ms;
      var_Reset = paReset;
      executeEvent(scmEventREQID, nullptr);
      paMotorOn = var_MotorOn;
      paContactorOn = var_ContactorOn;
      paErrorVoltage = var_ErrorVoltage;
      paErrorDrive = var_ErrorDrive;
      paErrorContactor = var_ErrorContactor;
    }

    void operator()(const CIEC_BOOL &paMotorRun, const CIEC_BOOL &paVoltageOk, const CIEC_BOOL &paDriveOk, const CIEC_BOOL &paContactorOk, const CIEC_UDINT &paTimeMonitoring, const CIEC_UDINT &paTimeDelayOn, const CIEC_UDINT &paTimeDelayOff, const CIEC_UDINT &paTs_ms, const CIEC_BOOL &paReset, CIEC_BOOL &paMotorOn, CIEC_BOOL &paContactorOn, CIEC_BOOL &paErrorVoltage, CIEC_BOOL &paErrorDrive, CIEC_BOOL &paErrorContactor) {
      evt_REQ(paMotorRun, paVoltageOk, paDriveOk, paContactorOk, paTimeMonitoring, paTimeDelayOn, paTimeDelayOff, paTs_ms, paReset, paMotorOn, paContactorOn, paErrorVoltage, paErrorDrive, paErrorContactor);
    }
};

