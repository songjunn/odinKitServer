// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessageLoadWorldData.proto

#ifndef PROTOBUF_MessageLoadWorldData_2eproto__INCLUDED
#define PROTOBUF_MessageLoadWorldData_2eproto__INCLUDED

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
void  protobuf_AddDesc_MessageLoadWorldData_2eproto();
void protobuf_AssignDesc_MessageLoadWorldData_2eproto();
void protobuf_ShutdownFile_MessageLoadWorldData_2eproto();

class LoadWorldData;

// ===================================================================

class LoadWorldData : public ::google::protobuf::Message {
 public:
  LoadWorldData();
  virtual ~LoadWorldData();

  LoadWorldData(const LoadWorldData& from);

  inline LoadWorldData& operator=(const LoadWorldData& from) {
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
  static const LoadWorldData& default_instance();

  void Swap(LoadWorldData* other);

  // implements Message ----------------------------------------------

  LoadWorldData* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const LoadWorldData& from);
  void MergeFrom(const LoadWorldData& from);
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

  // optional int64 itemid = 1;
  inline bool has_itemid() const;
  inline void clear_itemid();
  static const int kItemidFieldNumber = 1;
  inline ::google::protobuf::int64 itemid() const;
  inline void set_itemid(::google::protobuf::int64 value);

  // optional int64 heroid = 2;
  inline bool has_heroid() const;
  inline void clear_heroid();
  static const int kHeroidFieldNumber = 2;
  inline ::google::protobuf::int64 heroid() const;
  inline void set_heroid(::google::protobuf::int64 value);

  // optional int64 playerid = 3;
  inline bool has_playerid() const;
  inline void clear_playerid();
  static const int kPlayeridFieldNumber = 3;
  inline ::google::protobuf::int64 playerid() const;
  inline void set_playerid(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:Message.LoadWorldData)
 private:
  inline void set_has_itemid();
  inline void clear_has_itemid();
  inline void set_has_heroid();
  inline void clear_has_heroid();
  inline void set_has_playerid();
  inline void clear_has_playerid();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int64 itemid_;
  ::google::protobuf::int64 heroid_;
  ::google::protobuf::int64 playerid_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_MessageLoadWorldData_2eproto();
  friend void protobuf_AssignDesc_MessageLoadWorldData_2eproto();
  friend void protobuf_ShutdownFile_MessageLoadWorldData_2eproto();

  void InitAsDefaultInstance();
  static LoadWorldData* default_instance_;
};
// ===================================================================


// ===================================================================

// LoadWorldData

// optional int64 itemid = 1;
inline bool LoadWorldData::has_itemid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void LoadWorldData::set_has_itemid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void LoadWorldData::clear_has_itemid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void LoadWorldData::clear_itemid() {
  itemid_ = GOOGLE_LONGLONG(0);
  clear_has_itemid();
}
inline ::google::protobuf::int64 LoadWorldData::itemid() const {
  return itemid_;
}
inline void LoadWorldData::set_itemid(::google::protobuf::int64 value) {
  set_has_itemid();
  itemid_ = value;
}

// optional int64 heroid = 2;
inline bool LoadWorldData::has_heroid() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void LoadWorldData::set_has_heroid() {
  _has_bits_[0] |= 0x00000002u;
}
inline void LoadWorldData::clear_has_heroid() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void LoadWorldData::clear_heroid() {
  heroid_ = GOOGLE_LONGLONG(0);
  clear_has_heroid();
}
inline ::google::protobuf::int64 LoadWorldData::heroid() const {
  return heroid_;
}
inline void LoadWorldData::set_heroid(::google::protobuf::int64 value) {
  set_has_heroid();
  heroid_ = value;
}

// optional int64 playerid = 3;
inline bool LoadWorldData::has_playerid() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void LoadWorldData::set_has_playerid() {
  _has_bits_[0] |= 0x00000004u;
}
inline void LoadWorldData::clear_has_playerid() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void LoadWorldData::clear_playerid() {
  playerid_ = GOOGLE_LONGLONG(0);
  clear_has_playerid();
}
inline ::google::protobuf::int64 LoadWorldData::playerid() const {
  return playerid_;
}
inline void LoadWorldData::set_playerid(::google::protobuf::int64 value) {
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

#endif  // PROTOBUF_MessageLoadWorldData_2eproto__INCLUDED
