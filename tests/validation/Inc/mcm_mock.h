#ifndef _MCM_MOCK_H_
#define _MCM_MOCK_H_

#include <stdio.h>


#define MESH_ERR_CONNECTION_CLOSED 0

typedef int MeshClient;
typedef int MeshConnection; 
typedef struct MeshBuffer{
    void * const payload_ptr;
    const size_t payload_len;
}MeshBuffer;

const char* mesh_err2str(int err);
int mesh_create_client(MeshClient **client,const char *config_json);
void mesh_delete_client(MeshClient **client);
int mesh_shutdown_connection(MeshConnection **conn);

int mesh_create_tx_connection(MeshClient *client, MeshConnection **conn, const char *config_json);
int mesh_create_rx_connection(MeshClient *client, MeshConnection **conn, const char *config_json);

int mesh_get_buffer(MeshConnection *conn, MeshBuffer **buf);
int mesh_put_buffer(MeshBuffer **buf);

void put_user_video_frames(void * const ptr, const size_t len);
int get_user_video_frames(void * const ptr, const size_t len);



#endif /* _MCM_MOCK_H_*/