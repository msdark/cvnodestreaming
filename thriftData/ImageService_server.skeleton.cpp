// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "ImageService.h"
#include <protocol/TBinaryProtocol.h>
#include <server/TSimpleServer.h>
#include <transport/TServerSocket.h>
#include <transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

class ImageServiceHandler : virtual public ImageServiceIf {
 public:
  ImageServiceHandler() {
    // Your initialization goes here
  }

  bool receiveImage(const ImageData& image) {
    // Your implementation goes here
    printf("receiveImage\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  shared_ptr<ImageServiceHandler> handler(new ImageServiceHandler());
  shared_ptr<TProcessor> processor(new ImageServiceProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

