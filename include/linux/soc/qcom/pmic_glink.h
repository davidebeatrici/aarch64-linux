#ifndef __PMIC_GLINK_H__
#define __PMIC_GLINK_H__

struct pmic_glink;
struct pmic_glink_client;

#define PMIC_GLINK_OWNER_BC		32778
#define PMIC_GLINK_OWNER_UC		32779
#define PMIC_GLINK_OWNER_USBC_PAN	32780

#define PMIC_GLINK_REQ_RESP		1
#define PMIC_GLINK_NOTIFY		2

struct pmic_glink_hdr {
	__le32 owner;
	__le32 type;
	__le32 opcode;
};

int pmic_glink_send(struct pmic_glink_client *client, void *data, size_t len);


struct pmic_glink_client *devm_pmic_glink_register_client(struct device *dev,
							  unsigned int id,
							  void (*cb)(const void *, size_t, void *),
							  void *priv);

#endif
