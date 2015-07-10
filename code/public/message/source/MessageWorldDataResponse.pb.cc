// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessageWorldDataResponse.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "MessageWorldDataResponse.pb.h"

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

const ::google::protobuf::Descriptor* WorldDataResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  WorldDataResponse_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_MessageWorldDataResponse_2eproto() {
  protobuf_AddDesc_MessageWorldDataResponse_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "MessageWorldDataResponse.proto");
  GOOGLE_CHECK(file != NULL);
  WorldDataResponse_descriptor_ = file->message_type(0);
  static const int WorldDataResponse_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(WorldDataResponse, playerid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(WorldDataResponse, itemid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(WorldDataResponse, heroid_),
  };
  WorldDataResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      WorldDataResponse_descriptor_,
      WorldDataResponse::default_instance_,
      WorldDataResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(WorldDataResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(WorldDataResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(WorldDataResponse));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_MessageWorldDataResponse_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    WorldDataResponse_descriptor_, &WorldDataResponse::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_MessageWorldDataResponse_2eproto() {
  delete WorldDataResponse::default_instance_;
  delete WorldDataResponse_reflection_;
}

void protobuf_AddDesc_MessageWorldDataResponse_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\036MessageWorldDataResponse.proto\022\007Messag"
    "e\"E\n\021WorldDataResponse\022\020\n\010playerid\030\001 \001(\003"
    "\022\016\n\006itemid\030\002 \001(\003\022\016\n\006heroid\030\003 \001(\003", 112);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "MessageWorldDataResponse.proto", &protobuf_RegisterTypes);
  WorldDataResponse::default_instance_ = new WorldDataResponse();
  WorldDataResponse::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_MessageWorldDataResponse_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_MessageWorldDataResponse_2eproto {
  StaticDescriptorInitializer_MessageWorldDataResponse_2eproto() {
    protobuf_AddDesc_MessageWorldDataResponse_2eproto();
  }
} static_descriptor_initializer_MessageWorldDataResponse_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int WorldDataResponse::kPlayeridFieldNumber;
const int WorldDataResponse::kItemidFieldNumber;
const int WorldDataResponse::kHeroidFieldNumber;
#endif  // !_MSC_VER

WorldDataResponse::WorldDataResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void WorldDataResponse::InitAsDefaultInstance() {
}

WorldDataResponse::WorldDataResponse(const WorldDataResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void WorldDataResponse::SharedCtor() {
  _cached_size_ = 0;
  playerid_ = GOOGLE_LONGLONG(0);
  itemid_ = GOOGLE_LONGLONG(0);
  heroid_ = GOOGLE_LONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

WorldDataResponse::~WorldDataResponse() {
  SharedDtor();
}

void WorldDataResponse::SharedDtor() {
  if (this != default_instance_) {
  }
}

void WorldDataResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* WorldDataResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return WorldDataResponse_descriptor_;
}

const WorldDataResponse& WorldDataResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MessageWorldDataResponse_2eproto();
  return *default_instance_;
}

WorldDataResponse* WorldDataResponse::default_instance_ = NULL;

WorldDataResponse* WorldDataResponse::New() const {
  return new WorldDataResponse;
}

void WorldDataResponse::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    playerid_ = GOOGLE_LONGLONG(0);
    itemid_ = GOOGLE_LONGLONG(0);
    heroid_ = GOOGLE_LONGLONG(0);
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool WorldDataResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int64 playerid = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &playerid_)));
          set_has_playerid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_itemid;
        break;
      }

      // optional int64 itemid = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_itemid:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &itemid_)));
          set_has_itemid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_heroid;
        break;
      }

      // optional int64 heroid = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_heroid:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &heroid_)));
          set_has_heroid();
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

void WorldDataResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional int64 playerid = 1;
  if (has_playerid()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(1, this->playerid(), output);
  }

  // optional int64 itemid = 2;
  if (has_itemid()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(2, this->itemid(), output);
  }

  // optional int64 heroid = 3;
  if (has_heroid()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(3, this->heroid(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* WorldDataResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional int64 playerid = 1;
  if (has_playerid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(1, this->playerid(), target);
  }

  // optional int64 itemid = 2;
  if (has_itemid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(2, this->itemid(), target);
  }

  // optional int64 heroid = 3;
  if (has_heroid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(3, this->heroid(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int WorldDataResponse::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional int64 playerid = 1;
    if (has_playerid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->playerid());
    }

    // optional int64 itemid = 2;
    if (has_itemid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->itemid());
    }

    // optional int64 heroid = 3;
    if (has_heroid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->heroid());
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

void WorldDataResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const WorldDataResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const WorldDataResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void WorldDataResponse::MergeFrom(const WorldDataResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_playerid()) {
      set_playerid(from.playerid());
    }
    if (from.has_itemid()) {
      set_itemid(from.itemid());
    }
    if (from.has_heroid()) {
      set_heroid(from.heroid());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void WorldDataResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void WorldDataResponse::CopyFrom(const WorldDataResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool WorldDataResponse::IsInitialized() const {

  return true;
}

void WorldDataResponse::Swap(WorldDataResponse* other) {
  if (other != this) {
    std::swap(playerid_, other->playerid_);
    std::swap(itemid_, other->itemid_);
    std::swap(heroid_, other->heroid_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata WorldDataResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = WorldDataResponse_descriptor_;
  metadata.reflection = WorldDataResponse_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Message

// @@protoc_insertion_point(global_scope)
