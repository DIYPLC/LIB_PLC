/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbSimMotorGear
 *** Description: Виртуальный МЭО для отладки шагового регулятора.
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

class FORTE_FbSimMotorGear final : public CSimpleFB {
  DECLARE_FIRMWARE_FB(FORTE_FbSimMotorGear)

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

    CIEC_REAL var_SpeedPos;
    CIEC_REAL var_SpeedNeg;

    CIEC_ANY *getVarInternal(size_t) override;

    void alg_REQ(void);

    void enterStateREQ(CEventChainExecutionThread *const paECET);

    void executeEvent(TEventID paEIID, CEventChainExecutionThread *const paECET) override;

    void readInputData(TEventID paEIID) override;
    void writeOutputData(TEventID paEIID) override;
    void setInitialValues() override;

  public:
    FORTE_FbSimMotorGear(CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer);

    CIEC_BOOL var_CmdOpen;
    CIEC_BOOL var_CmdClose;
    CIEC_REAL var_TimeOpen;
    CIEC_REAL var_TimeClose;
    CIEC_REAL var_Ts;
    CIEC_BOOL var_Reset;

    CIEC_REAL var_Position;
    CIEC_BOOL var_SensorOpen;
    CIEC_BOOL var_SensorClose;

    CIEC_REAL var_conn_Position;
    CIEC_BOOL var_conn_SensorOpen;
    CIEC_BOOL var_conn_SensorClose;

    CEventConnection conn_CNF;

    CDataConnection *conn_CmdOpen;
    CDataConnection *conn_CmdClose;
    CDataConnection *conn_TimeOpen;
    CDataConnection *conn_TimeClose;
    CDataConnection *conn_Ts;
    CDataConnection *conn_Reset;

    CDataConnection conn_Position;
    CDataConnection conn_SensorOpen;
    CDataConnection conn_SensorClose;

    CIEC_ANY *getDI(size_t) override;
    CIEC_ANY *getDO(size_t) override;
    CEventConnection *getEOConUnchecked(TPortId) override;
    CDataConnection **getDIConUnchecked(TPortId) override;
    CDataConnection *getDOConUnchecked(TPortId) override;

    void evt_REQ(const CIEC_BOOL &paCmdOpen, const CIEC_BOOL &paCmdClose, const CIEC_REAL &paTimeOpen, const CIEC_REAL &paTimeClose, const CIEC_REAL &paTs, const CIEC_BOOL &paReset, CIEC_REAL &paPosition, CIEC_BOOL &paSensorOpen, CIEC_BOOL &paSensorClose) {
      var_CmdOpen = paCmdOpen;
      var_CmdClose = paCmdClose;
      var_TimeOpen = paTimeOpen;
      var_TimeClose = paTimeClose;
      var_Ts = paTs;
      var_Reset = paReset;
      executeEvent(scmEventREQID, nullptr);
      paPosition = var_Position;
      paSensorOpen = var_SensorOpen;
      paSensorClose = var_SensorClose;
    }

    void operator()(const CIEC_BOOL &paCmdOpen, const CIEC_BOOL &paCmdClose, const CIEC_REAL &paTimeOpen, const CIEC_REAL &paTimeClose, const CIEC_REAL &paTs, const CIEC_BOOL &paReset, CIEC_REAL &paPosition, CIEC_BOOL &paSensorOpen, CIEC_BOOL &paSensorClose) {
      evt_REQ(paCmdOpen, paCmdClose, paTimeOpen, paTimeClose, paTs, paReset, paPosition, paSensorOpen, paSensorClose);
    }
};

