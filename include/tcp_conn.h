#ifndef __TCP_CONN_H__
#define __TCP_CONN_H__

#include "event_loop.h"
#include "io_buffer.h"
#include "net_commu.h"

class tcp_conn: public net_commu
{
public:
    tcp_conn(int connfd, event_loop* loop);

    void handle_read();

    void handle_write();

    virtual void send_data(const char* data, uint32_t datlen);

private:
    int _connfd;
    event_loop* _loop;
    input_buffer ibuf;
    output_buffer obuf;
};

#endif