/* Copyright 2013-2018 Homegear GmbH
 *
 * Homegear is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * Homegear is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with Homegear.  If not, see
 * <http://www.gnu.org/licenses/>.
 *
 * In addition, as a special exception, the copyright holders give
 * permission to link the code of portions of this program with the
 * OpenSSL library under certain conditions as described in each
 * individual source file, and distribute linked combinations
 * including the two.
 * You must obey the GNU Lesser General Public License in all respects
 * for all of the code used other than OpenSSL.  If you modify
 * file(s) with this exception, you may extend this exception to your
 * version of the file(s), but you are not obligated to do so.  If you
 * do not wish to do so, delete this exception statement from your
 * version.  If you delete this exception statement from all source
 * files in the program, then also delete it here.
*/

#ifndef IPCCLIENT_H_
#define IPCCLIENT_H_

#include <homegear-base/BaseLib.h>
#include <homegear-ipc/IIpcClient.h>

#include <thread>
#include <mutex>
#include <string>
#include <set>

class IpcClient : public Ipc::IIpcClient
{
public:
    IpcClient(std::string socketPath);
    virtual ~IpcClient();

    void setOnConnect(std::function<void(void)> value) { _onConnect.swap(value); }
    void setBroadcastEvent(std::function<void(std::string& eventSource, uint64_t peerId, int32_t channel, std::string& variableName, Ipc::PVariable value)> value) { _broadcastEvent.swap(value); }
private:
    std::function<void(void)> _onConnect;
    std::function<void(std::string& eventSource, uint64_t peerId, int32_t channel, std::string& variableName, Ipc::PVariable value)> _broadcastEvent;

    virtual void onConnect();

    // {{{ RPC methods
    Ipc::PVariable broadcastEvent(Ipc::PArray& parameters);
    // }}}
};

#endif
