// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessageSwitchPosRequest.proto

#ifndef PROTOBUF_MessageSwitchPosRequest_2eproto__INCLUDED
#define PROTOBUF_MessageSwitchPosRequest_2eproto__INCLUDED

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
void  protobuf_AddDesc_MessageSwitchPosRequest_2eproto();
void protobuf_AssignDesc_MessageSwitchPosRequest_2eproto();
void protobuf_ShutdownFile_MessageSwitchPosRequest_2eproto();

class SwitchPosRequest;

// ===================================================================

class SwitchPosRequest : public ::google::protobuf::Message {
 public:
  SwitchPosRequest();
  virtual ~SwitchPosRequest();

  SwitchPosRequest(const SwitchPosRequest& from);

  inline SwitchPosRequest& operator=(const SwitchPosRequest& from) {
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
  static const SwitchPosRequest& default_instance();

  void Swap(SwitchPosRequest* other);

  // implements Message ----------------------------------------------

  SwitchPosRequest* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const SwitchPosRequest& from);
  void MergeFrom(const SwitchPosRequest& from);
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

  // repeated int64 heroid = 1;
  inline int heroid_size() const;
  inline void clear_heroid();
  static const int kHeroidFieldNumber = 1;
  inline ::google::protobuf::int64 heroid(int index) const;
  inline void set_heroid(int index, ::google::protobuf::int64 value);
  inline void add_heroid(::google::protobuf::int64 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::int64 >&
      heroid() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::int64 >*
      mutable_heroid();

  // repeated int32 curpos = 2;
  inline int curpos_size() const;
  inline void clear_curpos();
  static const int kCurposFieldNumber = 2;
  inline ::google::protobuf::int32 curpos(int index) const;
  inline void set_curpos(int index, ::google::protobuf::int32 value);
  inline void add_curpos(::google::protobuf::int32 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
      curpos() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
      mutable_curpos();

  // @@protoc_insertion_point(class_scope:Message.SwitchPosRequest)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedField< ::google::protobuf::int64 > heroid_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 > curpos_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_MessageSwitchPosRequest_2eproto();
  friend void protobuf_AssignDesc_MessageSwitchPosRequest_2eproto();
  friend void protobuf_ShutdownFile_MessageSwitchPosRequest_2eproto();

  void InitAsDefaultInstance();
  static SwitchPosRequest* default_instance_;
};
// ===================================================================


// ===================================================================

// SwitchPosRequest

// repeated int64 heroid = 1;
inline int SwitchPosRequest::heroid_size() const {
  return heroid_.size();
}
inline void SwitchPosRequest::clear_heroid() {
  heroid_.Clear();
}
inline ::google::protobuf::int64 SwitchPosRequest::heroid(int index) const {
  return heroid_.Get(index);
}
inline void SwitchPosRequest::set_heroid(int index, ::google::protobuf::int64 value) {
  heroid_.Set(index, value);
}
inline void SwitchPosRequest::add_heroid(::google::protobuf::int64 value) {
  heroid_.Add(value);
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int64 >&
SwitchPosRequest::heroid() const {
  return heroid_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int64 >*
SwitchPosRequest::mutable_heroid() {
  return &heroid_;
}

// repeated int32 curpos = 2;
inline int SwitchPosRequest::curpos_size() const {
  return curpos_.size();
}
inline void SwitchPosRequest::clear_curpos() {
  curpos_.Clear();
}
inline ::google::protobuf::int32 SwitchPosRequest::curpos(int index) const {
  return curpos_.Get(index);
}
inline void SwitchPosRequest::set_curpos(int index, ::google::protobuf::int32 value) {
  curpos_.Set(index, value);
}
inline void SwitchPosRequest::add_curpos(::google::protobuf::int32 value) {
  curpos_.Add(value);
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
SwitchPosRequest::curpos() const {
  return curpos_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
SwitchPosRequest::mutable_curpos() {
  return &curpos_;
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

#endif  // PROTOBUF_MessageSwitchPosRequest_2eproto__INCLUDED
