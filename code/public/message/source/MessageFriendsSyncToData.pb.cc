// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessageFriendsSyncToData.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "MessageFriendsSyncToData.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace Message {

namespace {

const ::google::protobuf::Descriptor* DataFriendAdd_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  DataFriendAdd_reflection_ = NULL;
const ::google::protobuf::Descriptor* DataFriendDel_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  DataFriendDel_reflection_ = NULL;
const ::google::protobuf::Descriptor* DataFriendRequestAdd_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  DataFriendRequestAdd_reflection_ = NULL;
const ::google::protobuf::Descriptor* DataFriendRequestDel_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  DataFriendRequestDel_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_MessageFriendsSyncToData_2eproto() {
  protobuf_AddDesc_MessageFriendsSyncToData_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "MessageFriendsSyncToData.proto");
  GOOGLE_CHECK(file != NULL);
  DataFriendAdd_descriptor_ = file->message_type(0);
  static const int DataFriendAdd_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DataFriendAdd, pid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DataFriendAdd, offline_),
  };
  DataFriendAdd_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      DataFriendAdd_descriptor_,
      DataFriendAdd::default_instance_,
      DataFriendAdd_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DataFriendAdd, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DataFriendAdd, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(DataFriendAdd));
  DataFriendDel_descriptor_ = file->message_type(1);
  static const int DataFriendDel_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DataFriendDel, pid_),
  };
  DataFriendDel_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      DataFriendDel_descriptor_,
      DataFriendDel::default_instance_,
      DataFriendDel_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DataFriendDel, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DataFriendDel, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(DataFriendDel));
  DataFriendRequestAdd_descriptor_ = file->message_type(2);
  static const int DataFriendRequestAdd_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DataFriendRequestAdd, pid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DataFriendRequestAdd, level_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DataFriendRequestAdd, fighter_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DataFriendRequestAdd, name_),
  };
  DataFriendRequestAdd_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      DataFriendRequestAdd_descriptor_,
      DataFriendRequestAdd::default_instance_,
      DataFriendRequestAdd_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DataFriendRequestAdd, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DataFriendRequestAdd, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(DataFriendRequestAdd));
  DataFriendRequestDel_descriptor_ = file->message_type(3);
  static const int DataFriendRequestDel_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DataFriendRequestDel, pid_),
  };
  DataFriendRequestDel_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      DataFriendRequestDel_descriptor_,
      DataFriendRequestDel::default_instance_,
      DataFriendRequestDel_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DataFriendRequestDel, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DataFriendRequestDel, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(DataFriendRequestDel));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_MessageFriendsSyncToData_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    DataFriendAdd_descriptor_, &DataFriendAdd::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    DataFriendDel_descriptor_, &DataFriendDel::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    DataFriendRequestAdd_descriptor_, &DataFriendRequestAdd::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    DataFriendRequestDel_descriptor_, &DataFriendRequestDel::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_MessageFriendsSyncToData_2eproto() {
  delete DataFriendAdd::default_instance_;
  delete DataFriendAdd_reflection_;
  delete DataFriendDel::default_instance_;
  delete DataFriendDel_reflection_;
  delete DataFriendRequestAdd::default_instance_;
  delete DataFriendRequestAdd_reflection_;
  delete DataFriendRequestDel::default_instance_;
  delete DataFriendRequestDel_reflection_;
}

void protobuf_AddDesc_MessageFriendsSyncToData_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\036MessageFriendsSyncToData.proto\022\007Messag"
    "e\"-\n\rDataFriendAdd\022\013\n\003pid\030\001 \001(\003\022\017\n\007offli"
    "ne\030\002 \001(\010\"\034\n\rDataFriendDel\022\013\n\003pid\030\001 \001(\003\"Q"
    "\n\024DataFriendRequestAdd\022\013\n\003pid\030\001 \001(\003\022\r\n\005l"
    "evel\030\002 \001(\005\022\017\n\007fighter\030\003 \001(\005\022\014\n\004name\030\004 \001("
    "\t\"#\n\024DataFriendRequestDel\022\013\n\003pid\030\001 \001(\003", 238);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "MessageFriendsSyncToData.proto", &protobuf_RegisterTypes);
  DataFriendAdd::default_instance_ = new DataFriendAdd();
  DataFriendDel::default_instance_ = new DataFriendDel();
  DataFriendRequestAdd::default_instance_ = new DataFriendRequestAdd();
  DataFriendRequestDel::default_instance_ = new DataFriendRequestDel();
  DataFriendAdd::default_instance_->InitAsDefaultInstance();
  DataFriendDel::default_instance_->InitAsDefaultInstance();
  DataFriendRequestAdd::default_instance_->InitAsDefaultInstance();
  DataFriendRequestDel::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_MessageFriendsSyncToData_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_MessageFriendsSyncToData_2eproto {
  StaticDescriptorInitializer_MessageFriendsSyncToData_2eproto() {
    protobuf_AddDesc_MessageFriendsSyncToData_2eproto();
  }
} static_descriptor_initializer_MessageFriendsSyncToData_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int DataFriendAdd::kPidFieldNumber;
const int DataFriendAdd::kOfflineFieldNumber;
#endif  // !_MSC_VER

DataFriendAdd::DataFriendAdd()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void DataFriendAdd::InitAsDefaultInstance() {
}

DataFriendAdd::DataFriendAdd(const DataFriendAdd& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void DataFriendAdd::SharedCtor() {
  _cached_size_ = 0;
  pid_ = GOOGLE_LONGLONG(0);
  offline_ = false;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

DataFriendAdd::~DataFriendAdd() {
  SharedDtor();
}

void DataFriendAdd::SharedDtor() {
  if (this != default_instance_) {
  }
}

void DataFriendAdd::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* DataFriendAdd::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return DataFriendAdd_descriptor_;
}

const DataFriendAdd& DataFriendAdd::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MessageFriendsSyncToData_2eproto();
  return *default_instance_;
}

DataFriendAdd* DataFriendAdd::default_instance_ = NULL;

DataFriendAdd* DataFriendAdd::New() const {
  return new DataFriendAdd;
}

void DataFriendAdd::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    pid_ = GOOGLE_LONGLONG(0);
    offline_ = false;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool DataFriendAdd::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int64 pid = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &pid_)));
          set_has_pid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_offline;
        break;
      }

      // optional bool offline = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_offline:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &offline_)));
          set_has_offline();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void DataFriendAdd::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional int64 pid = 1;
  if (has_pid()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(1, this->pid(), output);
  }

  // optional bool offline = 2;
  if (has_offline()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(2, this->offline(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* DataFriendAdd::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional int64 pid = 1;
  if (has_pid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(1, this->pid(), target);
  }

  // optional bool offline = 2;
  if (has_offline()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(2, this->offline(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int DataFriendAdd::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional int64 pid = 1;
    if (has_pid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->pid());
    }

    // optional bool offline = 2;
    if (has_offline()) {
      total_size += 1 + 1;
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void DataFriendAdd::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const DataFriendAdd* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const DataFriendAdd*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void DataFriendAdd::MergeFrom(const DataFriendAdd& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_pid()) {
      set_pid(from.pid());
    }
    if (from.has_offline()) {
      set_offline(from.offline());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void DataFriendAdd::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void DataFriendAdd::CopyFrom(const DataFriendAdd& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool DataFriendAdd::IsInitialized() const {

  return true;
}

void DataFriendAdd::Swap(DataFriendAdd* other) {
  if (other != this) {
    std::swap(pid_, other->pid_);
    std::swap(offline_, other->offline_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata DataFriendAdd::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = DataFriendAdd_descriptor_;
  metadata.reflection = DataFriendAdd_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int DataFriendDel::kPidFieldNumber;
#endif  // !_MSC_VER

DataFriendDel::DataFriendDel()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void DataFriendDel::InitAsDefaultInstance() {
}

DataFriendDel::DataFriendDel(const DataFriendDel& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void DataFriendDel::SharedCtor() {
  _cached_size_ = 0;
  pid_ = GOOGLE_LONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

DataFriendDel::~DataFriendDel() {
  SharedDtor();
}

void DataFriendDel::SharedDtor() {
  if (this != default_instance_) {
  }
}

void DataFriendDel::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* DataFriendDel::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return DataFriendDel_descriptor_;
}

const DataFriendDel& DataFriendDel::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MessageFriendsSyncToData_2eproto();
  return *default_instance_;
}

DataFriendDel* DataFriendDel::default_instance_ = NULL;

DataFriendDel* DataFriendDel::New() const {
  return new DataFriendDel;
}

void DataFriendDel::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    pid_ = GOOGLE_LONGLONG(0);
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool DataFriendDel::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int64 pid = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &pid_)));
          set_has_pid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void DataFriendDel::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional int64 pid = 1;
  if (has_pid()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(1, this->pid(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* DataFriendDel::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional int64 pid = 1;
  if (has_pid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(1, this->pid(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int DataFriendDel::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional int64 pid = 1;
    if (has_pid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->pid());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void DataFriendDel::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const DataFriendDel* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const DataFriendDel*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void DataFriendDel::MergeFrom(const DataFriendDel& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_pid()) {
      set_pid(from.pid());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void DataFriendDel::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void DataFriendDel::CopyFrom(const DataFriendDel& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool DataFriendDel::IsInitialized() const {

  return true;
}

void DataFriendDel::Swap(DataFriendDel* other) {
  if (other != this) {
    std::swap(pid_, other->pid_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata DataFriendDel::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = DataFriendDel_descriptor_;
  metadata.reflection = DataFriendDel_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int DataFriendRequestAdd::kPidFieldNumber;
const int DataFriendRequestAdd::kLevelFieldNumber;
const int DataFriendRequestAdd::kFighterFieldNumber;
const int DataFriendRequestAdd::kNameFieldNumber;
#endif  // !_MSC_VER

DataFriendRequestAdd::DataFriendRequestAdd()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void DataFriendRequestAdd::InitAsDefaultInstance() {
}

DataFriendRequestAdd::DataFriendRequestAdd(const DataFriendRequestAdd& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void DataFriendRequestAdd::SharedCtor() {
  _cached_size_ = 0;
  pid_ = GOOGLE_LONGLONG(0);
  level_ = 0;
  fighter_ = 0;
  name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

DataFriendRequestAdd::~DataFriendRequestAdd() {
  SharedDtor();
}

void DataFriendRequestAdd::SharedDtor() {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    delete name_;
  }
  if (this != default_instance_) {
  }
}

void DataFriendRequestAdd::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* DataFriendRequestAdd::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return DataFriendRequestAdd_descriptor_;
}

const DataFriendRequestAdd& DataFriendRequestAdd::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MessageFriendsSyncToData_2eproto();
  return *default_instance_;
}

DataFriendRequestAdd* DataFriendRequestAdd::default_instance_ = NULL;

DataFriendRequestAdd* DataFriendRequestAdd::New() const {
  return new DataFriendRequestAdd;
}

void DataFriendRequestAdd::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    pid_ = GOOGLE_LONGLONG(0);
    level_ = 0;
    fighter_ = 0;
    if (has_name()) {
      if (name_ != &::google::protobuf::internal::kEmptyString) {
        name_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool DataFriendRequestAdd::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int64 pid = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &pid_)));
          set_has_pid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_level;
        break;
      }

      // optional int32 level = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_level:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &level_)));
          set_has_level();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_fighter;
        break;
      }

      // optional int32 fighter = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_fighter:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &fighter_)));
          set_has_fighter();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(34)) goto parse_name;
        break;
      }

      // optional string name = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_name:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->name().data(), this->name().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void DataFriendRequestAdd::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional int64 pid = 1;
  if (has_pid()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(1, this->pid(), output);
  }

  // optional int32 level = 2;
  if (has_level()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->level(), output);
  }

  // optional int32 fighter = 3;
  if (has_fighter()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->fighter(), output);
  }

  // optional string name = 4;
  if (has_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      4, this->name(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* DataFriendRequestAdd::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional int64 pid = 1;
  if (has_pid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(1, this->pid(), target);
  }

  // optional int32 level = 2;
  if (has_level()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->level(), target);
  }

  // optional int32 fighter = 3;
  if (has_fighter()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->fighter(), target);
  }

  // optional string name = 4;
  if (has_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        4, this->name(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int DataFriendRequestAdd::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional int64 pid = 1;
    if (has_pid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->pid());
    }

    // optional int32 level = 2;
    if (has_level()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->level());
    }

    // optional int32 fighter = 3;
    if (has_fighter()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->fighter());
    }

    // optional string name = 4;
    if (has_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->name());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void DataFriendRequestAdd::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const DataFriendRequestAdd* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const DataFriendRequestAdd*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void DataFriendRequestAdd::MergeFrom(const DataFriendRequestAdd& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_pid()) {
      set_pid(from.pid());
    }
    if (from.has_level()) {
      set_level(from.level());
    }
    if (from.has_fighter()) {
      set_fighter(from.fighter());
    }
    if (from.has_name()) {
      set_name(from.name());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void DataFriendRequestAdd::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void DataFriendRequestAdd::CopyFrom(const DataFriendRequestAdd& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool DataFriendRequestAdd::IsInitialized() const {

  return true;
}

void DataFriendRequestAdd::Swap(DataFriendRequestAdd* other) {
  if (other != this) {
    std::swap(pid_, other->pid_);
    std::swap(level_, other->level_);
    std::swap(fighter_, other->fighter_);
    std::swap(name_, other->name_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata DataFriendRequestAdd::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = DataFriendRequestAdd_descriptor_;
  metadata.reflection = DataFriendRequestAdd_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int DataFriendRequestDel::kPidFieldNumber;
#endif  // !_MSC_VER

DataFriendRequestDel::DataFriendRequestDel()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void DataFriendRequestDel::InitAsDefaultInstance() {
}

DataFriendRequestDel::DataFriendRequestDel(const DataFriendRequestDel& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void DataFriendRequestDel::SharedCtor() {
  _cached_size_ = 0;
  pid_ = GOOGLE_LONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

DataFriendRequestDel::~DataFriendRequestDel() {
  SharedDtor();
}

void DataFriendRequestDel::SharedDtor() {
  if (this != default_instance_) {
  }
}

void DataFriendRequestDel::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* DataFriendRequestDel::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return DataFriendRequestDel_descriptor_;
}

const DataFriendRequestDel& DataFriendRequestDel::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MessageFriendsSyncToData_2eproto();
  return *default_instance_;
}

DataFriendRequestDel* DataFriendRequestDel::default_instance_ = NULL;

DataFriendRequestDel* DataFriendRequestDel::New() const {
  return new DataFriendRequestDel;
}

void DataFriendRequestDel::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    pid_ = GOOGLE_LONGLONG(0);
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool DataFriendRequestDel::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int64 pid = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &pid_)));
          set_has_pid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void DataFriendRequestDel::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional int64 pid = 1;
  if (has_pid()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(1, this->pid(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* DataFriendRequestDel::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional int64 pid = 1;
  if (has_pid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(1, this->pid(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int DataFriendRequestDel::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional int64 pid = 1;
    if (has_pid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->pid());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void DataFriendRequestDel::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const DataFriendRequestDel* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const DataFriendRequestDel*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void DataFriendRequestDel::MergeFrom(const DataFriendRequestDel& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_pid()) {
      set_pid(from.pid());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void DataFriendRequestDel::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void DataFriendRequestDel::CopyFrom(const DataFriendRequestDel& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool DataFriendRequestDel::IsInitialized() const {

  return true;
}

void DataFriendRequestDel::Swap(DataFriendRequestDel* other) {
  if (other != this) {
    std::swap(pid_, other->pid_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata DataFriendRequestDel::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = DataFriendRequestDel_descriptor_;
  metadata.reflection = DataFriendRequestDel_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Message

// @@protoc_insertion_point(global_scope)
