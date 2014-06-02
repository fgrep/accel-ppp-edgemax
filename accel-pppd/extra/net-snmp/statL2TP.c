/*
 * Note: this file originally auto-generated by mib2c using
 *        : mib2c.int_watch.conf 13957 2005-12-20 15:33:08Z tanders $
 */

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

#include "triton.h"
#include "statL2TP.h"


/*
 * The variables we want to tie the relevant OIDs to.
 * The agent will handle all GET and (if applicable) SET requests
 * to these variables automatically, changing the values as needed.
 */

void l2tp_get_stat(unsigned int **, unsigned int **);

static unsigned int *stat_starting;
static unsigned int *stat_active;

/*
 * Our initialization routine, called automatically by the agent 
 * (Note that the function name must match init_FILENAME()) 
 */
void
init_statL2TP(void)
{
  netsnmp_handler_registration *reg;
  netsnmp_watcher_info         *winfo;

    static oid statL2TPStarting_oid[] = { 1,3,6,1,4,1,8072,100,1,4,1 };
    static oid statL2TPActive_oid[] = { 1,3,6,1,4,1,8072,100,1,4,2 };

  /*
   * a debugging statement.  Run the agent with -DstatL2TP to see
   * the output of this debugging statement. 
   */
  DEBUGMSGTL(("statL2TP", "Initializing the statL2TP module\n"));

	if (!triton_module_loaded("l2tp"))
		return;

	l2tp_get_stat(&stat_starting, &stat_active);

    /*
     * Register scalar watchers for each of the MIB objects.
     * The ASN type and RO/RW status are taken from the MIB definition,
     * but can be adjusted if needed.
     *
     * In most circumstances, the scalar watcher will handle all
     * of the necessary processing.  But the NULL parameter in the
     * netsnmp_create_handler_registration() call can be used to
     * supply a user-provided handler if necessary.
     *
     * This approach can also be used to handle Counter64, string-
     * and OID-based watched scalars (although variable-sized writeable
     * objects will need some more specialised initialisation).
     */
    DEBUGMSGTL(("statL2TP",
                "Initializing statL2TPStarting scalar integer.  Default value = %d\n",
                0));
    reg = netsnmp_create_handler_registration(
             "statL2TPStarting", NULL,
              statL2TPStarting_oid, OID_LENGTH(statL2TPStarting_oid),
              HANDLER_CAN_RONLY);
    winfo = netsnmp_create_watcher_info(
                stat_starting, sizeof(*stat_starting),
                 ASN_INTEGER, WATCHER_FIXED_SIZE);
    if (netsnmp_register_watched_scalar( reg, winfo ) < 0 ) {
        snmp_log( LOG_ERR, "Failed to register watched statL2TPStarting" );
    }

    DEBUGMSGTL(("statL2TP",
                "Initializing statL2TPActive scalar integer.  Default value = %d\n",
                0));
    reg = netsnmp_create_handler_registration(
             "statL2TPActive", NULL,
              statL2TPActive_oid, OID_LENGTH(statL2TPActive_oid),
              HANDLER_CAN_RONLY);
    winfo = netsnmp_create_watcher_info(
                stat_active, sizeof(*stat_active),
                 ASN_INTEGER, WATCHER_FIXED_SIZE);
    if (netsnmp_register_watched_scalar( reg, winfo ) < 0 ) {
        snmp_log( LOG_ERR, "Failed to register watched statL2TPActive" );
    }


  DEBUGMSGTL(("statL2TP",
              "Done initalizing statL2TP module\n"));
}
