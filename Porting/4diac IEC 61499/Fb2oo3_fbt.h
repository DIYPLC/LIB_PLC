/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: Fb2oo3
 *** Description: Резервирование датчиков методом голосования.
 *** Version:
 ***     2.0: 2026-03-19/VA - LIB_PLC -
 *************************************************************************/

#pragma once

#include "core/simplefb.h"
#include "core/datatypes/forte_bool.h"
#include "core/datatypes/forte_real.h"
#include "core/datatypes/forte_uint.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

class FORTE_Fb2oo3 final : public CSimpleFB {
  DECLARE_FIRMWARE_FB(FORTE_Fb2oo3)

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

    CIEC_UINT var_State;
    CIEC_BOOL var_Er1Max;
    CIEC_BOOL var_Er2Max;
    CIEC_BOOL var_Er3Max;
    CIEC_BOOL var_Er1Min;
    CIEC_BOOL var_Er2Min;
    CIEC_BOOL var_Er3Min;
    CIEC_BOOL var_Er1Dif;
    CIEC_BOOL var_Er2Dif;
    CIEC_BOOL var_Er3Dif;

    static const CIEC_UINT var_const_STATE0_2oo3;
    static const CIEC_UINT var_const_STATE1_1oo2;
    static const CIEC_UINT var_const_STATE2_1oo2;
    static const CIEC_UINT var_const_STATE3_1oo1;
    static const CIEC_UINT var_const_STATE4_1oo2;
    static const CIEC_UINT var_const_STATE5_1oo1;
    static const CIEC_UINT var_const_STATE6_1oo1;
    static const CIEC_UINT var_const_STATE7_0_ER;

    CIEC_ANY *getVarInternal(size_t) override;

    void alg_REQ(void);

    void enterStateREQ(CEventChainExecutionThread *const paECET);

    void executeEvent(TEventID paEIID, CEventChainExecutionThread *const paECET) override;

    void readInputData(TEventID paEIID) override;
    void writeOutputData(TEventID paEIID) override;
    void setInitialValues() override;

  public:
    FORTE_Fb2oo3(CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer);

    CIEC_REAL var_In1;
    CIEC_REAL var_In2;
    CIEC_REAL var_In3;
    CIEC_BOOL var_ErIn1;
    CIEC_BOOL var_ErIn2;
    CIEC_BOOL var_ErIn3;
    CIEC_REAL var_DifMax;
    CIEC_REAL var_LimMax;
    CIEC_REAL var_LimMin;
    CIEC_REAL var_ValEr;

    CIEC_REAL var_Out;
    CIEC_BOOL var_ErOut;
    CIEC_BOOL var_Er1;
    CIEC_BOOL var_Er2;
    CIEC_BOOL var_Er3;

    CIEC_REAL var_conn_Out;
    CIEC_BOOL var_conn_ErOut;
    CIEC_BOOL var_conn_Er1;
    CIEC_BOOL var_conn_Er2;
    CIEC_BOOL var_conn_Er3;

    CEventConnection conn_CNF;

    CDataConnection *conn_In1;
    CDataConnection *conn_In2;
    CDataConnection *conn_In3;
    CDataConnection *conn_ErIn1;
    CDataConnection *conn_ErIn2;
    CDataConnection *conn_ErIn3;
    CDataConnection *conn_DifMax;
    CDataConnection *conn_LimMax;
    CDataConnection *conn_LimMin;
    CDataConnection *conn_ValEr;

    CDataConnection conn_Out;
    CDataConnection conn_ErOut;
    CDataConnection conn_Er1;
    CDataConnection conn_Er2;
    CDataConnection conn_Er3;

    CIEC_ANY *getDI(size_t) override;
    CIEC_ANY *getDO(size_t) override;
    CEventConnection *getEOConUnchecked(TPortId) override;
    CDataConnection **getDIConUnchecked(TPortId) override;
    CDataConnection *getDOConUnchecked(TPortId) override;

    void evt_REQ(const CIEC_REAL &paIn1, const CIEC_REAL &paIn2, const CIEC_REAL &paIn3, const CIEC_BOOL &paErIn1, const CIEC_BOOL &paErIn2, const CIEC_BOOL &paErIn3, const CIEC_REAL &paDifMax, const CIEC_REAL &paLimMax, const CIEC_REAL &paLimMin, const CIEC_REAL &paValEr, CIEC_REAL &paOut, CIEC_BOOL &paErOut, CIEC_BOOL &paEr1, CIEC_BOOL &paEr2, CIEC_BOOL &paEr3) {
      var_In1 = paIn1;
      var_In2 = paIn2;
      var_In3 = paIn3;
      var_ErIn1 = paErIn1;
      var_ErIn2 = paErIn2;
      var_ErIn3 = paErIn3;
      var_DifMax = paDifMax;
      var_LimMax = paLimMax;
      var_LimMin = paLimMin;
      var_ValEr = paValEr;
      executeEvent(scmEventREQID, nullptr);
      paOut = var_Out;
      paErOut = var_ErOut;
      paEr1 = var_Er1;
      paEr2 = var_Er2;
      paEr3 = var_Er3;
    }

    void operator()(const CIEC_REAL &paIn1, const CIEC_REAL &paIn2, const CIEC_REAL &paIn3, const CIEC_BOOL &paErIn1, const CIEC_BOOL &paErIn2, const CIEC_BOOL &paErIn3, const CIEC_REAL &paDifMax, const CIEC_REAL &paLimMax, const CIEC_REAL &paLimMin, const CIEC_REAL &paValEr, CIEC_REAL &paOut, CIEC_BOOL &paErOut, CIEC_BOOL &paEr1, CIEC_BOOL &paEr2, CIEC_BOOL &paEr3) {
      evt_REQ(paIn1, paIn2, paIn3, paErIn1, paErIn2, paErIn3, paDifMax, paLimMax, paLimMin, paValEr, paOut, paErOut, paEr1, paEr2, paEr3);
    }
};

