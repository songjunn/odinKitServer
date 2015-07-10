// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessageCityHelperRequest.proto

#ifndef PROTOBUF_MessageCityHelperRequest_2eproto__INCLUDED
#define PROTOBUF_MessageCityHelperRequest_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace Message {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_MessageCityHelperRequest_2eproto();
void protobuf_AssignDesc_MessageCityHelperRequest_2eproto();
void protobuf_ShutdownFile_MessageCityHelperRequest_2eproto();

class CityHelperRequest;

// ===================================================================

class CityHelperRequest : public ::google::protobuf::Message {
 public:
  CityHelperRequest();
  virtual ~CityHelperRequest();

  CityHelperRequest(const CityHelperRequest& from);

  inline CityHelperRequest& operator=(const CityHelperRequest& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const CityHelperRequest& default_instance();

  void Swap(CityHelperRequest* other);

  // implements Message ----------------------------------------------

  CityHelperRequest* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const CityHelperRequest& from);
  void MergeFrom(const CityHelperRequest& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional int64 playerid = 1;
  inline bool has_playerid() const;
  inline void clear_playerid();
  static const int kPlayeridFieldNumber = 1;
  inline ::google::protobuf::int64 playerid() const;
  inline void set_playerid(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:Message.CityHelperRequest)
 private:
  inline void set_has_playerid();
  inline void clear_has_playerid();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int64 playerid_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_MessageCityHelperRequest_2eproto();
  friend void protobuf_AssignDesc_MessageCityHelperRequest_2eproto();
  friend void protobuf_ShutdownFile_MessageCityHelperRequest_2eproto();

  void InitAsDefaultInstance();
  static CityHelperRequest* default_instance_;
};
// ===================================================================


// ===================================================================

// CityHelperRequest

// optional int64 playerid = 1;
inline bool CityHelperRequest::has_playerid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void CityHelperRequest::set_has_playerid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void CityHelperRequest::clear_has_playerid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void CityHelperRequest::clear_playerid() {
  playerid_ = GOOGLE_LONGLONG(0);
  clear_has_playerid();
}
inline ::google::protobuf::int64 CityHelperRequest::playerid() const {
  return playerid_;
}
inline void CityHelperRequest::set_playerid(::google::protobuf::int64 value) {
  set_has_playerid();
  playerid_ = value;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Message

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_MessageCityHelperRequest_2eproto__INCLUDED
