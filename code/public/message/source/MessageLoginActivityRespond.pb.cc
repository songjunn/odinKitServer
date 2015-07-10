// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessageLoginActivityRespond.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "MessageLoginActivityRespond.pb.h"

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

const ::google::protobuf::Descriptor* LoginActivityRespond_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  LoginActivityRespond_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_MessageLoginActivityRespond_2eproto() {
  protobuf_AddDesc_MessageLoginActivityRespond_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "MessageLoginActivityRespond.proto");
  GOOGLE_CHECK(file != NULL);
  LoginActivityRespond_descriptor_ = file->message_type(0);
  static const int LoginActivityRespond_offsets_[8] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LoginActivityRespond, restype_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LoginActivityRespond, acttype_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LoginActivityRespond, bshow_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LoginActivityRespond, starttime_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LoginActivityRespond, endtime_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LoginActivityRespond, recycle_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LoginActivityRespond, conlogindays_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LoginActivityRespond, bgetaward_),
  };
  LoginActivityRespond_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      LoginActivityRespond_descriptor_,
      LoginActivityRespond::default_instance_,
      LoginActivityRespond_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LoginActivityRespond, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LoginActivityRespond, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(LoginActivityRespond));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_MessageLoginActivityRespond_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    LoginActivityRespond_descriptor_, &LoginActivityRespond::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_MessageLoginActivityRespond_2eproto() {
  delete LoginActivityRespond::default_instance_;
  delete LoginActivityRespond_reflection_;
}

void protobuf_AddDesc_MessageLoginActivityRespond_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n!MessageLoginActivityRespond.proto\022\007Mes"
    "sage\"\245\001\n\024LoginActivityRespond\022\017\n\007restype"
    "\030\001 \001(\005\022\017\n\007acttype\030\002 \001(\005\022\r\n\005bshow\030\003 \001(\010\022\021"
    "\n\tstarttime\030\004 \001(\003\022\017\n\007endtime\030\005 \001(\003\022\017\n\007re"
    "cycle\030\006 \001(\005\022\024\n\014conlogindays\030\007 \001(\005\022\021\n\tbge"
    "taward\030\010 \001(\010", 212);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "MessageLoginActivityRespond.proto", &protobuf_RegisterTypes);
  LoginActivityRespond::default_instance_ = new LoginActivityRespond();
  LoginActivityRespond::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_MessageLoginActivityRespond_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_MessageLoginActivityRespond_2eproto {
  StaticDescriptorInitializer_MessageLoginActivityRespond_2eproto() {
    protobuf_AddDesc_MessageLoginActivityRespond_2eproto();
  }
} static_descriptor_initializer_MessageLoginActivityRespond_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int LoginActivityRespond::kRestypeFieldNumber;
const int LoginActivityRespond::kActtypeFieldNumber;
const int LoginActivityRespond::kBshowFieldNumber;
const int LoginActivityRespond::kStarttimeFieldNumber;
const int LoginActivityRespond::kEndtimeFieldNumber;
const int LoginActivityRespond::kRecycleFieldNumber;
const int LoginActivityRespond::kConlogindaysFieldNumber;
const int LoginActivityRespond::kBgetawardFieldNumber;
#endif  // !_MSC_VER

LoginActivityRespond::LoginActivityRespond()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void LoginActivityRespond::InitAsDefaultInstance() {
}

LoginActivityRespond::LoginActivityRespond(const LoginActivityRespond& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void LoginActivityRespond::SharedCtor() {
  _cached_size_ = 0;
  restype_ = 0;
  acttype_ = 0;
  bshow_ = false;
  starttime_ = GOOGLE_LONGLONG(0);
  endtime_ = GOOGLE_LONGLONG(0);
  recycle_ = 0;
  conlogindays_ = 0;
  bgetaward_ = false;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

LoginActivityRespond::~LoginActivityRespond() {
  SharedDtor();
}

void LoginActivityRespond::SharedDtor() {
  if (this != default_instance_) {
  }
}

void LoginActivityRespond::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* LoginActivityRespond::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return LoginActivityRespond_descriptor_;
}

const LoginActivityRespond& LoginActivityRespond::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MessageLoginActivityRespond_2eproto();
  return *default_instance_;
}

LoginActivityRespond* LoginActivityRespond::default_instance_ = NULL;

LoginActivityRespond* LoginActivityRespond::New() const {
  return new LoginActivityRespond;
}

void LoginActivityRespond::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    restype_ = 0;
    acttype_ = 0;
    bshow_ = false;
    starttime_ = GOOGLE_LONGLONG(0);
    endtime_ = GOOGLE_LONGLONG(0);
    recycle_ = 0;
    conlogindays_ = 0;
    bgetaward_ = false;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool LoginActivityRespond::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int32 restype = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &restype_)));
          set_has_restype();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_acttype;
        break;
      }

      // optional int32 acttype = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_acttype:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &acttype_)));
          set_has_acttype();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_bshow;
        break;
      }

      // optional bool bshow = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_bshow:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &bshow_)));
          set_has_bshow();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(32)) goto parse_starttime;
        break;
      }

      // optional int64 starttime = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_starttime:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &starttime_)));
          set_has_starttime();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(40)) goto parse_endtime;
        break;
      }

      // optional int64 endtime = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_endtime:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &endtime_)));
          set_has_endtime();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(48)) goto parse_recycle;
        break;
      }

      // optional int32 recycle = 6;
      case 6: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_recycle:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &recycle_)));
          set_has_recycle();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(56)) goto parse_conlogindays;
        break;
      }

      // optional int32 conlogindays = 7;
      case 7: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_conlogindays:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &conlogindays_)));
          set_has_conlogindays();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(64)) goto parse_bgetaward;
        break;
      }

      // optional bool bgetaward = 8;
      case 8: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_bgetaward:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &bgetaward_)));
          set_has_bgetaward();
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

void LoginActivityRespond::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional int32 restype = 1;
  if (has_restype()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->restype(), output);
  }

  // optional int32 acttype = 2;
  if (has_acttype()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->acttype(), output);
  }

  // optional bool bshow = 3;
  if (has_bshow()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(3, this->bshow(), output);
  }

  // optional int64 starttime = 4;
  if (has_starttime()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(4, this->starttime(), output);
  }

  // optional int64 endtime = 5;
  if (has_endtime()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(5, this->endtime(), output);
  }

  // optional int32 recycle = 6;
  if (has_recycle()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(6, this->recycle(), output);
  }

  // optional int32 conlogindays = 7;
  if (has_conlogindays()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(7, this->conlogindays(), output);
  }

  // optional bool bgetaward = 8;
  if (has_bgetaward()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(8, this->bgetaward(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* LoginActivityRespond::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional int32 restype = 1;
  if (has_restype()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->restype(), target);
  }

  // optional int32 acttype = 2;
  if (has_acttype()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->acttype(), target);
  }

  // optional bool bshow = 3;
  if (has_bshow()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(3, this->bshow(), target);
  }

  // optional int64 starttime = 4;
  if (has_starttime()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(4, this->starttime(), target);
  }

  // optional int64 endtime = 5;
  if (has_endtime()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(5, this->endtime(), target);
  }

  // optional int32 recycle = 6;
  if (has_recycle()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(6, this->recycle(), target);
  }

  // optional int32 conlogindays = 7;
  if (has_conlogindays()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(7, this->conlogindays(), target);
  }

  // optional bool bgetaward = 8;
  if (has_bgetaward()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(8, this->bgetaward(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int LoginActivityRespond::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional int32 restype = 1;
    if (has_restype()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->restype());
    }

    // optional int32 acttype = 2;
    if (has_acttype()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->acttype());
    }

    // optional bool bshow = 3;
    if (has_bshow()) {
      total_size += 1 + 1;
    }

    // optional int64 starttime = 4;
    if (has_starttime()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->starttime());
    }

    // optional int64 endtime = 5;
    if (has_endtime()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->endtime());
    }

    // optional int32 recycle = 6;
    if (has_recycle()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->recycle());
    }

    // optional int32 conlogindays = 7;
    if (has_conlogindays()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->conlogindays());
    }

    // optional bool bgetaward = 8;
    if (has_bgetaward()) {
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

void LoginActivityRespond::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const LoginActivityRespond* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const LoginActivityRespond*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void LoginActivityRespond::MergeFrom(const LoginActivityRespond& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_restype()) {
      set_restype(from.restype());
    }
    if (from.has_acttype()) {
      set_acttype(from.acttype());
    }
    if (from.has_bshow()) {
      set_bshow(from.bshow());
    }
    if (from.has_starttime()) {
      set_starttime(from.starttime());
    }
    if (from.has_endtime()) {
      set_endtime(from.endtime());
    }
    if (from.has_recycle()) {
      set_recycle(from.recycle());
    }
    if (from.has_conlogindays()) {
      set_conlogindays(from.conlogindays());
    }
    if (from.has_bgetaward()) {
      set_bgetaward(from.bgetaward());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void LoginActivityRespond::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void LoginActivityRespond::CopyFrom(const LoginActivityRespond& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool LoginActivityRespond::IsInitialized() const {

  return true;
}

void LoginActivityRespond::Swap(LoginActivityRespond* other) {
  if (other != this) {
    std::swap(restype_, other->restype_);
    std::swap(acttype_, other->acttype_);
    std::swap(bshow_, other->bshow_);
    std::swap(starttime_, other->starttime_);
    std::swap(endtime_, other->endtime_);
    std::swap(recycle_, other->recycle_);
    std::swap(conlogindays_, other->conlogindays_);
    std::swap(bgetaward_, other->bgetaward_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata LoginActivityRespond::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = LoginActivityRespond_descriptor_;
  metadata.reflection = LoginActivityRespond_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Message

// @@protoc_insertion_point(global_scope)
