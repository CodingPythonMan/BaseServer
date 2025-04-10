// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Protocol.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_Protocol_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_Protocol_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021012 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_Protocol_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_Protocol_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Protocol_2eproto;
class SLLog1Req;
struct SLLog1ReqDefaultTypeInternal;
extern SLLog1ReqDefaultTypeInternal _SLLog1Req_default_instance_;
class SLLog2Req;
struct SLLog2ReqDefaultTypeInternal;
extern SLLog2ReqDefaultTypeInternal _SLLog2Req_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::SLLog1Req* Arena::CreateMaybeMessage<::SLLog1Req>(Arena*);
template<> ::SLLog2Req* Arena::CreateMaybeMessage<::SLLog2Req>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class SLLog1Req final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:SLLog1Req) */ {
 public:
  inline SLLog1Req() : SLLog1Req(nullptr) {}
  ~SLLog1Req() override;
  explicit PROTOBUF_CONSTEXPR SLLog1Req(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  SLLog1Req(const SLLog1Req& from);
  SLLog1Req(SLLog1Req&& from) noexcept
    : SLLog1Req() {
    *this = ::std::move(from);
  }

  inline SLLog1Req& operator=(const SLLog1Req& from) {
    CopyFrom(from);
    return *this;
  }
  inline SLLog1Req& operator=(SLLog1Req&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const SLLog1Req& default_instance() {
    return *internal_default_instance();
  }
  static inline const SLLog1Req* internal_default_instance() {
    return reinterpret_cast<const SLLog1Req*>(
               &_SLLog1Req_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(SLLog1Req& a, SLLog1Req& b) {
    a.Swap(&b);
  }
  inline void Swap(SLLog1Req* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(SLLog1Req* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  SLLog1Req* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<SLLog1Req>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const SLLog1Req& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const SLLog1Req& from) {
    SLLog1Req::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(SLLog1Req* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "SLLog1Req";
  }
  protected:
  explicit SLLog1Req(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kTextFieldNumber = 1,
    kAFieldNumber = 2,
    kBFieldNumber = 3,
  };
  // string text = 1;
  void clear_text();
  const std::string& text() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_text(ArgT0&& arg0, ArgT... args);
  std::string* mutable_text();
  PROTOBUF_NODISCARD std::string* release_text();
  void set_allocated_text(std::string* text);
  private:
  const std::string& _internal_text() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_text(const std::string& value);
  std::string* _internal_mutable_text();
  public:

  // int32 a = 2;
  void clear_a();
  int32_t a() const;
  void set_a(int32_t value);
  private:
  int32_t _internal_a() const;
  void _internal_set_a(int32_t value);
  public:

  // int32 b = 3;
  void clear_b();
  int32_t b() const;
  void set_b(int32_t value);
  private:
  int32_t _internal_b() const;
  void _internal_set_b(int32_t value);
  public:

  // @@protoc_insertion_point(class_scope:SLLog1Req)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr text_;
    int32_t a_;
    int32_t b_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_Protocol_2eproto;
};
// -------------------------------------------------------------------

class SLLog2Req final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:SLLog2Req) */ {
 public:
  inline SLLog2Req() : SLLog2Req(nullptr) {}
  ~SLLog2Req() override;
  explicit PROTOBUF_CONSTEXPR SLLog2Req(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  SLLog2Req(const SLLog2Req& from);
  SLLog2Req(SLLog2Req&& from) noexcept
    : SLLog2Req() {
    *this = ::std::move(from);
  }

  inline SLLog2Req& operator=(const SLLog2Req& from) {
    CopyFrom(from);
    return *this;
  }
  inline SLLog2Req& operator=(SLLog2Req&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const SLLog2Req& default_instance() {
    return *internal_default_instance();
  }
  static inline const SLLog2Req* internal_default_instance() {
    return reinterpret_cast<const SLLog2Req*>(
               &_SLLog2Req_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(SLLog2Req& a, SLLog2Req& b) {
    a.Swap(&b);
  }
  inline void Swap(SLLog2Req* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(SLLog2Req* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  SLLog2Req* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<SLLog2Req>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const SLLog2Req& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const SLLog2Req& from) {
    SLLog2Req::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(SLLog2Req* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "SLLog2Req";
  }
  protected:
  explicit SLLog2Req(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kUniqueIDFieldNumber = 1,
    kDirectionFieldNumber = 2,
    kIsMoveFieldNumber = 3,
    kXFieldNumber = 4,
    kYFieldNumber = 5,
  };
  // int64 UniqueID = 1;
  void clear_uniqueid();
  int64_t uniqueid() const;
  void set_uniqueid(int64_t value);
  private:
  int64_t _internal_uniqueid() const;
  void _internal_set_uniqueid(int64_t value);
  public:

  // int32 Direction = 2;
  void clear_direction();
  int32_t direction() const;
  void set_direction(int32_t value);
  private:
  int32_t _internal_direction() const;
  void _internal_set_direction(int32_t value);
  public:

  // bool IsMove = 3;
  void clear_ismove();
  bool ismove() const;
  void set_ismove(bool value);
  private:
  bool _internal_ismove() const;
  void _internal_set_ismove(bool value);
  public:

  // float X = 4;
  void clear_x();
  float x() const;
  void set_x(float value);
  private:
  float _internal_x() const;
  void _internal_set_x(float value);
  public:

  // float Y = 5;
  void clear_y();
  float y() const;
  void set_y(float value);
  private:
  float _internal_y() const;
  void _internal_set_y(float value);
  public:

  // @@protoc_insertion_point(class_scope:SLLog2Req)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    int64_t uniqueid_;
    int32_t direction_;
    bool ismove_;
    float x_;
    float y_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_Protocol_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// SLLog1Req

// string text = 1;
inline void SLLog1Req::clear_text() {
  _impl_.text_.ClearToEmpty();
}
inline const std::string& SLLog1Req::text() const {
  // @@protoc_insertion_point(field_get:SLLog1Req.text)
  return _internal_text();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void SLLog1Req::set_text(ArgT0&& arg0, ArgT... args) {
 
 _impl_.text_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:SLLog1Req.text)
}
inline std::string* SLLog1Req::mutable_text() {
  std::string* _s = _internal_mutable_text();
  // @@protoc_insertion_point(field_mutable:SLLog1Req.text)
  return _s;
}
inline const std::string& SLLog1Req::_internal_text() const {
  return _impl_.text_.Get();
}
inline void SLLog1Req::_internal_set_text(const std::string& value) {
  
  _impl_.text_.Set(value, GetArenaForAllocation());
}
inline std::string* SLLog1Req::_internal_mutable_text() {
  
  return _impl_.text_.Mutable(GetArenaForAllocation());
}
inline std::string* SLLog1Req::release_text() {
  // @@protoc_insertion_point(field_release:SLLog1Req.text)
  return _impl_.text_.Release();
}
inline void SLLog1Req::set_allocated_text(std::string* text) {
  if (text != nullptr) {
    
  } else {
    
  }
  _impl_.text_.SetAllocated(text, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.text_.IsDefault()) {
    _impl_.text_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:SLLog1Req.text)
}

// int32 a = 2;
inline void SLLog1Req::clear_a() {
  _impl_.a_ = 0;
}
inline int32_t SLLog1Req::_internal_a() const {
  return _impl_.a_;
}
inline int32_t SLLog1Req::a() const {
  // @@protoc_insertion_point(field_get:SLLog1Req.a)
  return _internal_a();
}
inline void SLLog1Req::_internal_set_a(int32_t value) {
  
  _impl_.a_ = value;
}
inline void SLLog1Req::set_a(int32_t value) {
  _internal_set_a(value);
  // @@protoc_insertion_point(field_set:SLLog1Req.a)
}

// int32 b = 3;
inline void SLLog1Req::clear_b() {
  _impl_.b_ = 0;
}
inline int32_t SLLog1Req::_internal_b() const {
  return _impl_.b_;
}
inline int32_t SLLog1Req::b() const {
  // @@protoc_insertion_point(field_get:SLLog1Req.b)
  return _internal_b();
}
inline void SLLog1Req::_internal_set_b(int32_t value) {
  
  _impl_.b_ = value;
}
inline void SLLog1Req::set_b(int32_t value) {
  _internal_set_b(value);
  // @@protoc_insertion_point(field_set:SLLog1Req.b)
}

// -------------------------------------------------------------------

// SLLog2Req

// int64 UniqueID = 1;
inline void SLLog2Req::clear_uniqueid() {
  _impl_.uniqueid_ = int64_t{0};
}
inline int64_t SLLog2Req::_internal_uniqueid() const {
  return _impl_.uniqueid_;
}
inline int64_t SLLog2Req::uniqueid() const {
  // @@protoc_insertion_point(field_get:SLLog2Req.UniqueID)
  return _internal_uniqueid();
}
inline void SLLog2Req::_internal_set_uniqueid(int64_t value) {
  
  _impl_.uniqueid_ = value;
}
inline void SLLog2Req::set_uniqueid(int64_t value) {
  _internal_set_uniqueid(value);
  // @@protoc_insertion_point(field_set:SLLog2Req.UniqueID)
}

// int32 Direction = 2;
inline void SLLog2Req::clear_direction() {
  _impl_.direction_ = 0;
}
inline int32_t SLLog2Req::_internal_direction() const {
  return _impl_.direction_;
}
inline int32_t SLLog2Req::direction() const {
  // @@protoc_insertion_point(field_get:SLLog2Req.Direction)
  return _internal_direction();
}
inline void SLLog2Req::_internal_set_direction(int32_t value) {
  
  _impl_.direction_ = value;
}
inline void SLLog2Req::set_direction(int32_t value) {
  _internal_set_direction(value);
  // @@protoc_insertion_point(field_set:SLLog2Req.Direction)
}

// bool IsMove = 3;
inline void SLLog2Req::clear_ismove() {
  _impl_.ismove_ = false;
}
inline bool SLLog2Req::_internal_ismove() const {
  return _impl_.ismove_;
}
inline bool SLLog2Req::ismove() const {
  // @@protoc_insertion_point(field_get:SLLog2Req.IsMove)
  return _internal_ismove();
}
inline void SLLog2Req::_internal_set_ismove(bool value) {
  
  _impl_.ismove_ = value;
}
inline void SLLog2Req::set_ismove(bool value) {
  _internal_set_ismove(value);
  // @@protoc_insertion_point(field_set:SLLog2Req.IsMove)
}

// float X = 4;
inline void SLLog2Req::clear_x() {
  _impl_.x_ = 0;
}
inline float SLLog2Req::_internal_x() const {
  return _impl_.x_;
}
inline float SLLog2Req::x() const {
  // @@protoc_insertion_point(field_get:SLLog2Req.X)
  return _internal_x();
}
inline void SLLog2Req::_internal_set_x(float value) {
  
  _impl_.x_ = value;
}
inline void SLLog2Req::set_x(float value) {
  _internal_set_x(value);
  // @@protoc_insertion_point(field_set:SLLog2Req.X)
}

// float Y = 5;
inline void SLLog2Req::clear_y() {
  _impl_.y_ = 0;
}
inline float SLLog2Req::_internal_y() const {
  return _impl_.y_;
}
inline float SLLog2Req::y() const {
  // @@protoc_insertion_point(field_get:SLLog2Req.Y)
  return _internal_y();
}
inline void SLLog2Req::_internal_set_y(float value) {
  
  _impl_.y_ = value;
}
inline void SLLog2Req::set_y(float value) {
  _internal_set_y(value);
  // @@protoc_insertion_point(field_set:SLLog2Req.Y)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_Protocol_2eproto
