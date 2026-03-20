/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbSoftPWM
 *** Description: ШИМ генератор двухканальный.
 *** Version:
 ***     2.1: 2026-03-20/VA - LIB_PLC -
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

class FORTE_FbSoftPWM final : public CSimpleFB {
  DECLARE_FIRMWARE_FB(FORTE_FbSoftPWM)

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

    CIEC_REAL var_TimerPositive;
    CIEC_REAL var_TimerNegative;
    CIEC_REAL var_Percent;
    CIEC_REAL var_TimePulsePositive;
    CIEC_REAL var_TimePulseNegative;

    CIEC_ANY *getVarInternal(size_t) override;

    void alg_REQ(void);

    void enterStateREQ(CEventChainExecutionThread *const paECET);

    void executeEvent(TEventID paEIID, CEventChainExecutionThread *const paECET) override;

    void readInputData(TEventID paEIID) override;
    void writeOutputData(TEventID paEIID) override;
    void setInitialValues() override;

  public:
    FORTE_FbSoftPWM(CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer);

    CIEC_REAL var_DutyCucle;
    CIEC_REAL var_PeriodPositive;
    CIEC_REAL var_PeriodNegative;
    CIEC_REAL var_DBMAX;
    CIEC_REAL var_DBMIN;
    CIEC_REAL var_Ts;

    CIEC_BOOL var_PWMPOS;
    CIEC_BOOL var_PWMNEG;

    CIEC_BOOL var_conn_PWMPOS;
    CIEC_BOOL var_conn_PWMNEG;

    CEventConnection conn_CNF;

    CDataConnection *conn_DutyCucle;
    CDataConnection *conn_PeriodPositive;
    CDataConnection *conn_PeriodNegative;
    CDataConnection *conn_DBMAX;
    CDataConnection *conn_DBMIN;
    CDataConnection *conn_Ts;

    CDataConnection conn_PWMPOS;
    CDataConnection conn_PWMNEG;

    CIEC_ANY *getDI(size_t) override;
    CIEC_ANY *getDO(size_t) override;
    CEventConnection *getEOConUnchecked(TPortId) override;
    CDataConnection **getDIConUnchecked(TPortId) override;
    CDataConnection *getDOConUnchecked(TPortId) override;

    void evt_REQ(const CIEC_REAL &paDutyCucle, const CIEC_REAL &paPeriodPositive, const CIEC_REAL &paPeriodNegative, const CIEC_REAL &paDBMAX, const CIEC_REAL &paDBMIN, const CIEC_REAL &paTs, CIEC_BOOL &paPWMPOS, CIEC_BOOL &paPWMNEG) {
      var_DutyCucle = paDutyCucle;
      var_PeriodPositive = paPeriodPositive;
      var_PeriodNegative = paPeriodNegative;
      var_DBMAX = paDBMAX;
      var_DBMIN = paDBMIN;
      var_Ts = paTs;
      executeEvent(scmEventREQID, nullptr);
      paPWMPOS = var_PWMPOS;
      paPWMNEG = var_PWMNEG;
    }

    void operator()(const CIEC_REAL &paDutyCucle, const CIEC_REAL &paPeriodPositive, const CIEC_REAL &paPeriodNegative, const CIEC_REAL &paDBMAX, const CIEC_REAL &paDBMIN, const CIEC_REAL &paTs, CIEC_BOOL &paPWMPOS, CIEC_BOOL &paPWMNEG) {
      evt_REQ(paDutyCucle, paPeriodPositive, paPeriodNegative, paDBMAX, paDBMIN, paTs, paPWMPOS, paPWMNEG);
    }
};

