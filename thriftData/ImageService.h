/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 */
#ifndef ImageService_H
#define ImageService_H

#include <TProcessor.h>
#include "service_types.h"



class ImageServiceIf {
 public:
  virtual ~ImageServiceIf() {}
  virtual bool receiveImage(const ImageData& image) = 0;
};

class ImageServiceNull : virtual public ImageServiceIf {
 public:
  virtual ~ImageServiceNull() {}
  bool receiveImage(const ImageData& /* image */) {
    bool _return = false;
    return _return;
  }
};

typedef struct _ImageService_receiveImage_args__isset {
  _ImageService_receiveImage_args__isset() : image(false) {}
  bool image;
} _ImageService_receiveImage_args__isset;

class ImageService_receiveImage_args {
 public:

  ImageService_receiveImage_args() {
  }

  virtual ~ImageService_receiveImage_args() throw() {}

  ImageData image;

  _ImageService_receiveImage_args__isset __isset;

  bool operator == (const ImageService_receiveImage_args & rhs) const
  {
    if (!(image == rhs.image))
      return false;
    return true;
  }
  bool operator != (const ImageService_receiveImage_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageService_receiveImage_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ImageService_receiveImage_pargs {
 public:


  virtual ~ImageService_receiveImage_pargs() throw() {}

  const ImageData* image;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageService_receiveImage_result__isset {
  _ImageService_receiveImage_result__isset() : success(false) {}
  bool success;
} _ImageService_receiveImage_result__isset;

class ImageService_receiveImage_result {
 public:

  ImageService_receiveImage_result() : success(0) {
  }

  virtual ~ImageService_receiveImage_result() throw() {}

  bool success;

  _ImageService_receiveImage_result__isset __isset;

  bool operator == (const ImageService_receiveImage_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const ImageService_receiveImage_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageService_receiveImage_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageService_receiveImage_presult__isset {
  _ImageService_receiveImage_presult__isset() : success(false) {}
  bool success;
} _ImageService_receiveImage_presult__isset;

class ImageService_receiveImage_presult {
 public:


  virtual ~ImageService_receiveImage_presult() throw() {}

  bool* success;

  _ImageService_receiveImage_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class ImageServiceClient : virtual public ImageServiceIf {
 public:
  ImageServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  ImageServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    piprot_(iprot),
    poprot_(oprot) {
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  bool receiveImage(const ImageData& image);
  void send_receiveImage(const ImageData& image);
  bool recv_receiveImage();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class ImageServiceProcessor : virtual public ::apache::thrift::TProcessor {
 protected:
  boost::shared_ptr<ImageServiceIf> iface_;
  virtual bool process_fn(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, std::string& fname, int32_t seqid, void* callContext);
 private:
  std::map<std::string, void (ImageServiceProcessor::*)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*)> processMap_;
  void process_receiveImage(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  ImageServiceProcessor(boost::shared_ptr<ImageServiceIf> iface) :
    iface_(iface) {
    processMap_["receiveImage"] = &ImageServiceProcessor::process_receiveImage;
  }

  virtual bool process(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot, void* callContext);
  virtual ~ImageServiceProcessor() {}
};

class ImageServiceMultiface : virtual public ImageServiceIf {
 public:
  ImageServiceMultiface(std::vector<boost::shared_ptr<ImageServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~ImageServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<ImageServiceIf> > ifaces_;
  ImageServiceMultiface() {}
  void add(boost::shared_ptr<ImageServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  bool receiveImage(const ImageData& image) {
    uint32_t sz = ifaces_.size();
    for (uint32_t i = 0; i < sz; ++i) {
      if (i == sz - 1) {
        return ifaces_[i]->receiveImage(image);
      } else {
        ifaces_[i]->receiveImage(image);
      }
    }
  }

};



#endif
