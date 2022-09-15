static VALUE ossl_asn1_ ## klass ( int argc , VALUE * argv , VALUE self ) \ {
 return rb_funcall3 ( cASN1 ## klass , rb_intern ( "new" ) , argc , argv ) ;
 }
 OSSL_ASN1_IMPL_FACTORY_METHOD ( Boolean ) OSSL_ASN1_IMPL_FACTORY_METHOD ( Integer ) OSSL_ASN1_IMPL_FACTORY_METHOD ( Enumerated ) OSSL_ASN1_IMPL_FACTORY_METHOD ( BitString ) OSSL_ASN1_IMPL_FACTORY_METHOD ( OctetString ) OSSL_ASN1_IMPL_FACTORY_METHOD ( UTF8String ) OSSL_ASN1_IMPL_FACTORY_METHOD ( NumericString ) OSSL_ASN1_IMPL_FACTORY_METHOD ( PrintableString ) OSSL_ASN1_IMPL_FACTORY_METHOD ( T61String ) OSSL_ASN1_IMPL_FACTORY_METHOD ( VideotexString ) OSSL_ASN1_IMPL_FACTORY_METHOD ( IA5String ) OSSL_ASN1_IMPL_FACTORY_METHOD ( GraphicString ) OSSL_ASN1_IMPL_FACTORY_METHOD ( ISO64String ) OSSL_ASN1_IMPL_FACTORY_METHOD ( GeneralString ) OSSL_ASN1_IMPL_FACTORY_METHOD ( UniversalString ) OSSL_ASN1_IMPL_FACTORY_METHOD ( BMPString ) OSSL_ASN1_IMPL_FACTORY_METHOD ( Null ) OSSL_ASN1_IMPL_FACTORY_METHOD ( ObjectId ) OSSL_ASN1_IMPL_FACTORY_METHOD ( UTCTime ) OSSL_ASN1_IMPL_FACTORY_METHOD ( GeneralizedTime ) OSSL_ASN1_IMPL_FACTORY_METHOD ( Sequence ) OSSL_ASN1_IMPL_FACTORY_METHOD ( Set )