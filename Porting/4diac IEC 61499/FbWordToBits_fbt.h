/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbWordToBits
 *** Description: Преобразование слова в 16 бит.
 *** Version:
 ***     2.1: 2026-03-20/VA - LIB_PLC -
 *************************************************************************/

#pragma once

#include "core/simplefb.h"
#include "core/datatypes/forte_bool.h"
#include "core/datatypes/forte_word.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

class FORTE_FbWordToBits final : public CSimpleFB {
  DECLARE_FIRMWARE_FB(FORTE_FbWordToBits)

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

    CIEC_ANY *getVarInternal(size_t) override;

    void alg_REQ(void);

    void enterStateREQ(CEventChainExecutionThread *const paECET);

    void executeEvent(TEventID paEIID, CEventChainExecutionThread *const paECET) override;

    void readInputData(TEventID paEIID) override;
    void writeOutputData(TEventID paEIID) override;
    void setInitialValues() override;

  public:
    FORTE_FbWordToBits(CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer);

    CIEC_WORD var_In;

    CIEC_BOOL var_Out0;
    CIEC_BOOL var_Out1;
    CIEC_BOOL var_Out2;
    CIEC_BOOL var_Out3;
    CIEC_BOOL var_Out4;
    CIEC_BOOL var_Out5;
    CIEC_BOOL var_Out6;
    CIEC_BOOL var_Out7;
    CIEC_BOOL var_Out8;
    CIEC_BOOL var_Out9;
    CIEC_BOOL var_Out10;
    CIEC_BOOL var_Out11;
    CIEC_BOOL var_Out12;
    CIEC_BOOL var_Out13;
    CIEC_BOOL var_Out14;
    CIEC_BOOL var_Out15;

    CIEC_BOOL var_conn_Out0;
    CIEC_BOOL var_conn_Out1;
    CIEC_BOOL var_conn_Out2;
    CIEC_BOOL var_conn_Out3;
    CIEC_BOOL var_conn_Out4;
    CIEC_BOOL var_conn_Out5;
    CIEC_BOOL var_conn_Out6;
    CIEC_BOOL var_conn_Out7;
    CIEC_BOOL var_conn_Out8;
    CIEC_BOOL var_conn_Out9;
    CIEC_BOOL var_conn_Out10;
    CIEC_BOOL var_conn_Out11;
    CIEC_BOOL var_conn_Out12;
    CIEC_BOOL var_conn_Out13;
    CIEC_BOOL var_conn_Out14;
    CIEC_BOOL var_conn_Out15;

    CEventConnection conn_CNF;

    CDataConnection *conn_In;

    CDataConnection conn_Out0;
    CDataConnection conn_Out1;
    CDataConnection conn_Out2;
    CDataConnection conn_Out3;
    CDataConnection conn_Out4;
    CDataConnection conn_Out5;
    CDataConnection conn_Out6;
    CDataConnection conn_Out7;
    CDataConnection conn_Out8;
    CDataConnection conn_Out9;
    CDataConnection conn_Out10;
    CDataConnection conn_Out11;
    CDataConnection conn_Out12;
    CDataConnection conn_Out13;
    CDataConnection conn_Out14;
    CDataConnection conn_Out15;

    CIEC_ANY *getDI(size_t) override;
    CIEC_ANY *getDO(size_t) override;
    CEventConnection *getEOConUnchecked(TPortId) override;
    CDataConnection **getDIConUnchecked(TPortId) override;
    CDataConnection *getDOConUnchecked(TPortId) override;

    void evt_REQ(const CIEC_WORD &paIn, CIEC_BOOL &paOut0, CIEC_BOOL &paOut1, CIEC_BOOL &paOut2, CIEC_BOOL &paOut3, CIEC_BOOL &paOut4, CIEC_BOOL &paOut5, CIEC_BOOL &paOut6, CIEC_BOOL &paOut7, CIEC_BOOL &paOut8, CIEC_BOOL &paOut9, CIEC_BOOL &paOut10, CIEC_BOOL &paOut11, CIEC_BOOL &paOut12, CIEC_BOOL &paOut13, CIEC_BOOL &paOut14, CIEC_BOOL &paOut15) {
      var_In = paIn;
      executeEvent(scmEventREQID, nullptr);
      paOut0 = var_Out0;
      paOut1 = var_Out1;
      paOut2 = var_Out2;
      paOut3 = var_Out3;
      paOut4 = var_Out4;
      paOut5 = var_Out5;
      paOut6 = var_Out6;
      paOut7 = var_Out7;
      paOut8 = var_Out8;
      paOut9 = var_Out9;
      paOut10 = var_Out10;
      paOut11 = var_Out11;
      paOut12 = var_Out12;
      paOut13 = var_Out13;
      paOut14 = var_Out14;
      paOut15 = var_Out15;
    }

    void operator()(const CIEC_WORD &paIn, CIEC_BOOL &paOut0, CIEC_BOOL &paOut1, CIEC_BOOL &paOut2, CIEC_BOOL &paOut3, CIEC_BOOL &paOut4, CIEC_BOOL &paOut5, CIEC_BOOL &paOut6, CIEC_BOOL &paOut7, CIEC_BOOL &paOut8, CIEC_BOOL &paOut9, CIEC_BOOL &paOut10, CIEC_BOOL &paOut11, CIEC_BOOL &paOut12, CIEC_BOOL &paOut13, CIEC_BOOL &paOut14, CIEC_BOOL &paOut15) {
      evt_REQ(paIn, paOut0, paOut1, paOut2, paOut3, paOut4, paOut5, paOut6, paOut7, paOut8, paOut9, paOut10, paOut11, paOut12, paOut13, paOut14, paOut15);
    }
};

