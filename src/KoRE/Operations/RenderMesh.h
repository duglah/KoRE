/*
  Copyright © 2012 The KoRE Project

  This file is part of KoRE.

  KoRE is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  KoRE is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with KoRE.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CORE_INCLUDE_CORE_RENDERMESHOP_H_
#define CORE_INCLUDE_CORE_RENDERMESHOP_H_

#include "KoRE/Operations/Operation.h"
#include "KoRE/Components/MeshComponent.h"
#include "KoRE/Components/Camera.h"
#include "KoRE/ShaderProgram.h"

namespace kore {
  class RenderMesh: public Operation {
  public:
    explicit RenderMesh(void);
    explicit RenderMesh(const kore::MeshComponentPtr& mesh,
                        const kore::ShaderPtr& shader);

    virtual ~RenderMesh(void);
    virtual void execute(void);
    virtual void update(void);
    virtual void reset(void);
    virtual bool isValid(void);
    virtual bool dependsOn(const void* thing);

    void connect(const kore::MeshComponentPtr& mesh,
                 const kore::ShaderPtr& shader);

    const kore::MeshComponentPtr& getMesh() const;
    void setMesh(const kore::MeshComponentPtr& mesh);

    const kore::ShaderPtr& getShader() const;
    void setShader(const kore::ShaderPtr& shader);

  private:
    kore::MeshComponentPtr _meshComponent;
    kore::ShaderPtr _shader;
  };
  typedef std::shared_ptr<RenderMesh> RenderMeshOpPtr;
};
#endif  // CORE_INCLUDE_CORE_RENDERMESHOP_H_
