// smart_traffic/traffic.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/can.h>
#include <linux/can/raw.h>

int main() {
    int s;
    struct sockaddr_can addr;
    struct ifreq ifr;
    struct can_frame frame;

    s = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    strcpy(ifr.ifr_name, "vcan0");
    ioctl(s, SIOCGIFINDEX, &ifr);

    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    bind(s, (struct sockaddr *)&addr, sizeof(addr));

    while (1) {
        read(s, &frame, sizeof(struct can_frame));
        if (frame.can_id == 0x102 && frame.can_dlc == 1) {
            if (frame.data[0] == 1)
                printf("Traffic Light: Car detected! GREEN Light\n");
            else
                printf("Traffic Light: No car. RED Light\n");
        }
    }
    return 0;
}