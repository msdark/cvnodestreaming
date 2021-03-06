//
// Autogenerated by Thrift
//
// DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
//
var Thrift = require('thrift').Thrift;
var ttypes = module.exports = {};
var ImageData = module.exports.ImageData = function(args){
  this.data = null
  this.width = null
  this.height = null
if( args != null ){  if (null != args.data)
  this.data = args.data
  if (null != args.width)
  this.width = args.width
  if (null != args.height)
  this.height = args.height
}}
ImageData.prototype = {}
ImageData.prototype.read = function(input){ 
  var ret = input.readStructBegin()
  while (1) 
  {
    var ret = input.readFieldBegin()
    var fname = ret.fname
    var ftype = ret.ftype
    var fid   = ret.fid
    if (ftype == Thrift.Type.STOP) 
      break
    switch(fid)
    {
      case 1:      if (ftype == Thrift.Type.STRING) {
        this.data = input.readString()
      } else {
        input.skip(ftype)
      }
      break
      case 2:      if (ftype == Thrift.Type.I32) {
        this.width = input.readI32()
      } else {
        input.skip(ftype)
      }
      break
      case 3:      if (ftype == Thrift.Type.I32) {
        this.height = input.readI32()
      } else {
        input.skip(ftype)
      }
      break
      default:
        input.skip(ftype)
    }
    input.readFieldEnd()
  }
  input.readStructEnd()
  return
}

ImageData.prototype.write = function(output){ 
  output.writeStructBegin('ImageData')
  if (null != this.data) {
    output.writeFieldBegin('data', Thrift.Type.STRING, 1)
    output.writeString(this.data)
    output.writeFieldEnd()
  }
  if (null != this.width) {
    output.writeFieldBegin('width', Thrift.Type.I32, 2)
    output.writeI32(this.width)
    output.writeFieldEnd()
  }
  if (null != this.height) {
    output.writeFieldBegin('height', Thrift.Type.I32, 3)
    output.writeI32(this.height)
    output.writeFieldEnd()
  }
  output.writeFieldStop()
  output.writeStructEnd()
  return
}

