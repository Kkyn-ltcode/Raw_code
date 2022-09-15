TEST ( DownloadInterruptReasonEnumsSynced , DownloadInterruptReasonEnumsSynced ) {
 # define INTERRUPT_REASON ( name , value ) EXPECT_EQ ( InterruptReasonContentToExtension ( download : : DOWNLOAD_INTERRUPT_REASON_ ## name ) , downloads : : INTERRUPT_REASON_ ## name ) ;
 EXPECT_EQ ( InterruptReasonExtensionToComponent ( downloads : : INTERRUPT_REASON_ ## name ) , download : : DOWNLOAD_INTERRUPT_REASON_ ## name ) ;
 # include "components/download/public/common/download_interrupt_reason_values.h" # undef INTERRUPT_REASON }