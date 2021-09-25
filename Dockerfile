FROM alpine:edge

RUN apk add --no-cache g++ sfml-dev zip bash \
&& mkdir -p /usr/build

WORKDIR /usr/build

VOLUME [ "/usr/build" ]
