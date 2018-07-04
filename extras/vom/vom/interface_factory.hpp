/*
 * Copyright (c) 2017 Cisco and/or its affiliates.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __VOM_INTERFACE_FACTORY_H__
#define __VOM_INTERFACE_FACTORY_H__

#include <vapi/vapi.hpp>

#include "vom/bond_member.hpp"
#include "vom/interface.hpp"
#include "vom/tap_interface.hpp"

#include <vapi/af_packet.api.vapi.hpp>
#include <vapi/bond.api.vapi.hpp>
#include <vapi/interface.api.vapi.hpp>
#include <vapi/tap.api.vapi.hpp>
#include <vapi/tapv2.api.vapi.hpp>
#include <vapi/vhost_user.api.vapi.hpp>

namespace VOM {

class interface_factory
{
public:
  /**
   * Factory method to construct a new interface from the VPP record
   */
  static std::shared_ptr<interface> new_interface(
    const vapi_payload_sw_interface_details& vd);

  static std::shared_ptr<interface> new_vhost_user_interface(
    const vapi_payload_sw_interface_vhost_user_details& vd);

  static std::shared_ptr<interface> new_af_packet_interface(
    const vapi_payload_af_packet_details& vd);

  static std::shared_ptr<tap_interface> new_tap_interface(
    const vapi_payload_sw_interface_tap_details& vd);

  static std::shared_ptr<tap_interface> new_tap_v2_interface(
    const vapi_payload_sw_interface_tap_v2_details& vd);

  static std::shared_ptr<bond_interface> new_bond_interface(
    const vapi_payload_sw_interface_bond_details& vd);

  static bond_member new_bond_member_interface(
    const vapi_payload_sw_interface_slave_details& vd);
};
};

/*
 * fd.io coding-style-patch-verification: ON
 *
 * Local Variables:
 * eval: (c-set-style "mozilla")
 * End:
 */
#endif
