//:
// \file
#include <btol/btol_edge_algs.h>
#include <vtol/vtol_topology_object_sptr.h>
#include <vtol/vtol_topology_object.h>
#include <vtol/vtol_edge_2d.h>
#include <vcl_iostream.h>

const double btol_edge_algs::tol = 1e-6;

//: Destructor
btol_edge_algs::~btol_edge_algs()
{
}

//:
//-----------------------------------------------------------------------------
// Splits e at v and returns the two edges e1, e2, which are incident at v.
// If v is not within etol of a point on edge e then false is returned, and
// e is not split
//-----------------------------------------------------------------------------
bool btol_edge_algs::split_edge_2d(vtol_vertex_2d_sptr& v, vtol_edge_2d_sptr& e,
                                   vtol_edge_2d_sptr& e1, vtol_edge_2d_sptr& e2)
{
  vcl_cout << "tol " << btol_edge_algs::tol << vcl_endl;
  vcl_cout << "btol_edge_algs::split_edge_2d - not implemented " << vcl_endl;
 return true;
}

bool btol_edge_algs::unlink_all_inferiors_twoway(vtol_edge_2d_sptr& e)
{
  if (!e->v1()||!e->v2())
    return false;
  vtol_topology_object_sptr tv1 = e->v1()->cast_to_topology_object();
  vtol_topology_object_sptr tv2 = e->v2()->cast_to_topology_object();

  vtol_topology_object_sptr toe = e->cast_to_topology_object();
  vcl_vector<vtol_topology_object_sptr>* infs = toe->inferiors();
  //this will be the zero_chain for the edge
  if (infs->size()!=1)
    {
      vcl_cout << " In btol_edge_algs::unlink_all_inferiors_twoway(..) "
               << " inferiors inconsistent size " << vcl_endl;
      return false;
    }
  vtol_topology_object_sptr inf_two_chain = (*infs)[0];
  if (!inf_two_chain)
    {
      vcl_cout << " In btol_edge_algs::unlink_all_inferiors_twoway(..) "
               << " null two chain " << vcl_endl;
      return false;
    }
  toe->unlink_inferior(*inf_two_chain);
  inf_two_chain->unlink_inferior(*tv1);
  inf_two_chain->unlink_inferior(*tv2);
  return true;
}

//:
//-----------------------------------------------------------------------------
// Replaces va by vb on edge e.
//-----------------------------------------------------------------------------
bool btol_edge_algs::subst_vertex_on_edge(vtol_vertex_sptr& va,
                                          vtol_vertex_sptr& vb,
                                          vtol_edge_sptr& e)
{
  //not implemented
  return true;
}
