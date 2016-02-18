#ifndef IOTVT_SRM_SECURITY_INTERNALS_H
#define IOTVT_SRM_SECURITY_INTERNALS_H

#ifdef __cplusplus
extern "C" {
#endif

OicSecAcl_t* CBORPayloadToAcl(const uint8_t *payload, const size_t size);

void DeleteACLList(OicSecAcl_t* acl);

/**
 * This internal method is to retrieve the default ACL.
 * If SVR database in persistent storage got corrupted or
 * is not available for some reason, a default ACL is created
 * which allows user to initiate ACL provisioning again.
 */
OCStackResult  GetDefaultACL(OicSecAcl_t** defaultAcl);

/**
 * This internal method is the entity handler for ACL resources and
 * will handle REST request (GET/PUT/POST/DEL) for them.
 */
OCEntityHandlerResult ACLEntityHandler(OCEntityHandlerFlag flag,
            OCEntityHandlerRequest * ehRequest, void* callbackParameter);

OCStackResult SetDefaultACL(OicSecAcl_t *acl);

/**
 * Converts CBOR payload to SVC.
 *
 * @param cborPayload is the svc payload cbor value that neds to be converted.
 * @param cborSize of the cborPayload. In case size is not known, it is 0.
 * @param svc is the value that is initialized. It is NULL in case of error.
 *
 * @return ::OC_STACK_OK in case successful. ::OC_STACK_INVALID_PARAM if one of
 * the passed parameter is NULL. ::OC_STACK_ERROR in case of error.
 */
OCStackResult CBORPayloadToSVC(const uint8_t *cborPayload, size_t size, OicSecSvc_t **svc);

/**
 * Deletes the passed initialized reference to @ref OicSecSvc_t.
 *
 * @param svc is the reference to be deleted.
 */
void DeleteSVCList(OicSecSvc_t* svc);

/**
 * Create PSTAT resource after default PSTAT initialization is done.
 */
OCStackResult CreatePstatResource();

/**
 * This internal method is the entity handler for PSTAT resources and
 * will handle REST request (GET/PUT/POST/DEL) for them.
 */
OCEntityHandlerResult PstatEntityHandler(OCEntityHandlerFlag flag,
                                         OCEntityHandlerRequest * ehRequest);

#ifdef __cplusplus
}
#endif

#endif //IOTVT_SRM_SECURITY_INTERNALS_H
