//THIS FILE IS AUTOGENERATED

#include "CTimings.hpp"
#include "CLogger.hpp"

#include <fstream>

#include <boost/program_options.hpp>
#include <boost/program_options/options_description.hpp>

namespace po = boost::program_options;

namespace freedm {
namespace broker {

namespace {

CLocalLogger Logger(__FILE__);

}

unsigned int CTimings::GM_PHASE_TIME;

unsigned int CTimings::GM_FID_TIMEOUT;

unsigned int CTimings::SC_PHASE_TIME;

unsigned int CTimings::RTDS_RUN_DELAY;

unsigned int CTimings::GM_AYC_RESPONSE_TIMEOUT;

unsigned int CTimings::GM_AYT_RESPONSE_TIMEOUT;

unsigned int CTimings::CS_EXCHANGE_TIME;

unsigned int CTimings::GM_GLOBAL_TIMEOUT;

unsigned int CTimings::LB_GLOBAL_TIMER;

unsigned int CTimings::GM_PREMERGE_MAX_TIMEOUT;

unsigned int CTimings::CSRC_RESEND_TIME;

unsigned int CTimings::GM_INVITE_RESPONSE_TIMEOUT;

unsigned int CTimings::GM_PREMERGE_GRANULARITY;

unsigned int CTimings::GM_PREMERGE_MIN_TIMEOUT;

unsigned int CTimings::LB_STATE_TIMER;

unsigned int CTimings::GM_CHECK_TIMEOUT;

unsigned int CTimings::LB_SC_QUERY_TIME;

unsigned int CTimings::CSUC_RESEND_TIME;

unsigned int CTimings::GM_TIMEOUT_TIMEOUT;

unsigned int CTimings::CSRC_DEFAULT_TIMEOUT;

unsigned int CTimings::LB_PHASE_TIME;



void CTimings::SetTimings(const std::string timingsFile)
{ 
    std::ifstream ifs;

    po::options_description loggerOpts("Timing Parameters");
    po::variables_map vm;
    std::string desc;

    desc = "The timing value GM_PHASE_TIME";
    loggerOpts.add_options()
        ("GM_PHASE_TIME",
        po::value<unsigned int>( ),
        desc.c_str() );

    desc = "The timing value GM_FID_TIMEOUT";
    loggerOpts.add_options()
        ("GM_FID_TIMEOUT",
        po::value<unsigned int>( ),
        desc.c_str() );

    desc = "The timing value SC_PHASE_TIME";
    loggerOpts.add_options()
        ("SC_PHASE_TIME",
        po::value<unsigned int>( ),
        desc.c_str() );

    desc = "The timing value RTDS_RUN_DELAY";
    loggerOpts.add_options()
        ("RTDS_RUN_DELAY",
        po::value<unsigned int>( ),
        desc.c_str() );

    desc = "The timing value GM_AYC_RESPONSE_TIMEOUT";
    loggerOpts.add_options()
        ("GM_AYC_RESPONSE_TIMEOUT",
        po::value<unsigned int>( ),
        desc.c_str() );

    desc = "The timing value GM_AYT_RESPONSE_TIMEOUT";
    loggerOpts.add_options()
        ("GM_AYT_RESPONSE_TIMEOUT",
        po::value<unsigned int>( ),
        desc.c_str() );

    desc = "The timing value CS_EXCHANGE_TIME";
    loggerOpts.add_options()
        ("CS_EXCHANGE_TIME",
        po::value<unsigned int>( ),
        desc.c_str() );

    desc = "The timing value GM_GLOBAL_TIMEOUT";
    loggerOpts.add_options()
        ("GM_GLOBAL_TIMEOUT",
        po::value<unsigned int>( ),
        desc.c_str() );

    desc = "The timing value LB_GLOBAL_TIMER";
    loggerOpts.add_options()
        ("LB_GLOBAL_TIMER",
        po::value<unsigned int>( ),
        desc.c_str() );

    desc = "The timing value GM_PREMERGE_MAX_TIMEOUT";
    loggerOpts.add_options()
        ("GM_PREMERGE_MAX_TIMEOUT",
        po::value<unsigned int>( ),
        desc.c_str() );

    desc = "The timing value CSRC_RESEND_TIME";
    loggerOpts.add_options()
        ("CSRC_RESEND_TIME",
        po::value<unsigned int>( ),
        desc.c_str() );

    desc = "The timing value GM_INVITE_RESPONSE_TIMEOUT";
    loggerOpts.add_options()
        ("GM_INVITE_RESPONSE_TIMEOUT",
        po::value<unsigned int>( ),
        desc.c_str() );

    desc = "The timing value GM_PREMERGE_GRANULARITY";
    loggerOpts.add_options()
        ("GM_PREMERGE_GRANULARITY",
        po::value<unsigned int>( ),
        desc.c_str() );

    desc = "The timing value GM_PREMERGE_MIN_TIMEOUT";
    loggerOpts.add_options()
        ("GM_PREMERGE_MIN_TIMEOUT",
        po::value<unsigned int>( ),
        desc.c_str() );

    desc = "The timing value LB_STATE_TIMER";
    loggerOpts.add_options()
        ("LB_STATE_TIMER",
        po::value<unsigned int>( ),
        desc.c_str() );

    desc = "The timing value GM_CHECK_TIMEOUT";
    loggerOpts.add_options()
        ("GM_CHECK_TIMEOUT",
        po::value<unsigned int>( ),
        desc.c_str() );

    desc = "The timing value LB_SC_QUERY_TIME";
    loggerOpts.add_options()
        ("LB_SC_QUERY_TIME",
        po::value<unsigned int>( ),
        desc.c_str() );

    desc = "The timing value CSUC_RESEND_TIME";
    loggerOpts.add_options()
        ("CSUC_RESEND_TIME",
        po::value<unsigned int>( ),
        desc.c_str() );

    desc = "The timing value GM_TIMEOUT_TIMEOUT";
    loggerOpts.add_options()
        ("GM_TIMEOUT_TIMEOUT",
        po::value<unsigned int>( ),
        desc.c_str() );

    desc = "The timing value CSRC_DEFAULT_TIMEOUT";
    loggerOpts.add_options()
        ("CSRC_DEFAULT_TIMEOUT",
        po::value<unsigned int>( ),
        desc.c_str() );

    desc = "The timing value LB_PHASE_TIME";
    loggerOpts.add_options()
        ("LB_PHASE_TIME",
        po::value<unsigned int>( ),
        desc.c_str() );



    ifs.open(timingsFile.c_str());
    if (!ifs)
    {
        Logger.Error << "Unable to timing config file: "
                << timingsFile << std::endl;
        std::exit(-1);
    }
    else
    {
        // Process the config
        po::store(parse_config_file(ifs, loggerOpts), vm);
        po::notify(vm);
        Logger.Info << "timer config file " << timingsFile <<
                " successfully loaded." << std::endl;
    }
    ifs.close();

    try
    {
        GM_PHASE_TIME = vm["GM_PHASE_TIME"].as<unsigned int>();
    }
    catch (boost::bad_any_cast& e)
    {
        throw std::runtime_error(
                "GM_PHASE_TIME is missing, please check your timings config");
    }

    try
    {
        GM_FID_TIMEOUT = vm["GM_FID_TIMEOUT"].as<unsigned int>();
    }
    catch (boost::bad_any_cast& e)
    {
        throw std::runtime_error(
                "GM_FID_TIMEOUT is missing, please check your timings config");
    }

    try
    {
        SC_PHASE_TIME = vm["SC_PHASE_TIME"].as<unsigned int>();
    }
    catch (boost::bad_any_cast& e)
    {
        throw std::runtime_error(
                "SC_PHASE_TIME is missing, please check your timings config");
    }

    try
    {
        RTDS_RUN_DELAY = vm["RTDS_RUN_DELAY"].as<unsigned int>();
    }
    catch (boost::bad_any_cast& e)
    {
        throw std::runtime_error(
                "RTDS_RUN_DELAY is missing, please check your timings config");
    }

    try
    {
        GM_AYC_RESPONSE_TIMEOUT = vm["GM_AYC_RESPONSE_TIMEOUT"].as<unsigned int>();
    }
    catch (boost::bad_any_cast& e)
    {
        throw std::runtime_error(
                "GM_AYC_RESPONSE_TIMEOUT is missing, please check your timings config");
    }

    try
    {
        GM_AYT_RESPONSE_TIMEOUT = vm["GM_AYT_RESPONSE_TIMEOUT"].as<unsigned int>();
    }
    catch (boost::bad_any_cast& e)
    {
        throw std::runtime_error(
                "GM_AYT_RESPONSE_TIMEOUT is missing, please check your timings config");
    }

    try
    {
        CS_EXCHANGE_TIME = vm["CS_EXCHANGE_TIME"].as<unsigned int>();
    }
    catch (boost::bad_any_cast& e)
    {
        throw std::runtime_error(
                "CS_EXCHANGE_TIME is missing, please check your timings config");
    }

    try
    {
        GM_GLOBAL_TIMEOUT = vm["GM_GLOBAL_TIMEOUT"].as<unsigned int>();
    }
    catch (boost::bad_any_cast& e)
    {
        throw std::runtime_error(
                "GM_GLOBAL_TIMEOUT is missing, please check your timings config");
    }

    try
    {
        LB_GLOBAL_TIMER = vm["LB_GLOBAL_TIMER"].as<unsigned int>();
    }
    catch (boost::bad_any_cast& e)
    {
        throw std::runtime_error(
                "LB_GLOBAL_TIMER is missing, please check your timings config");
    }

    try
    {
        GM_PREMERGE_MAX_TIMEOUT = vm["GM_PREMERGE_MAX_TIMEOUT"].as<unsigned int>();
    }
    catch (boost::bad_any_cast& e)
    {
        throw std::runtime_error(
                "GM_PREMERGE_MAX_TIMEOUT is missing, please check your timings config");
    }

    try
    {
        CSRC_RESEND_TIME = vm["CSRC_RESEND_TIME"].as<unsigned int>();
    }
    catch (boost::bad_any_cast& e)
    {
        throw std::runtime_error(
                "CSRC_RESEND_TIME is missing, please check your timings config");
    }

    try
    {
        GM_INVITE_RESPONSE_TIMEOUT = vm["GM_INVITE_RESPONSE_TIMEOUT"].as<unsigned int>();
    }
    catch (boost::bad_any_cast& e)
    {
        throw std::runtime_error(
                "GM_INVITE_RESPONSE_TIMEOUT is missing, please check your timings config");
    }

    try
    {
        GM_PREMERGE_GRANULARITY = vm["GM_PREMERGE_GRANULARITY"].as<unsigned int>();
    }
    catch (boost::bad_any_cast& e)
    {
        throw std::runtime_error(
                "GM_PREMERGE_GRANULARITY is missing, please check your timings config");
    }

    try
    {
        GM_PREMERGE_MIN_TIMEOUT = vm["GM_PREMERGE_MIN_TIMEOUT"].as<unsigned int>();
    }
    catch (boost::bad_any_cast& e)
    {
        throw std::runtime_error(
                "GM_PREMERGE_MIN_TIMEOUT is missing, please check your timings config");
    }

    try
    {
        LB_STATE_TIMER = vm["LB_STATE_TIMER"].as<unsigned int>();
    }
    catch (boost::bad_any_cast& e)
    {
        throw std::runtime_error(
                "LB_STATE_TIMER is missing, please check your timings config");
    }

    try
    {
        GM_CHECK_TIMEOUT = vm["GM_CHECK_TIMEOUT"].as<unsigned int>();
    }
    catch (boost::bad_any_cast& e)
    {
        throw std::runtime_error(
                "GM_CHECK_TIMEOUT is missing, please check your timings config");
    }

    try
    {
        LB_SC_QUERY_TIME = vm["LB_SC_QUERY_TIME"].as<unsigned int>();
    }
    catch (boost::bad_any_cast& e)
    {
        throw std::runtime_error(
                "LB_SC_QUERY_TIME is missing, please check your timings config");
    }

    try
    {
        CSUC_RESEND_TIME = vm["CSUC_RESEND_TIME"].as<unsigned int>();
    }
    catch (boost::bad_any_cast& e)
    {
        throw std::runtime_error(
                "CSUC_RESEND_TIME is missing, please check your timings config");
    }

    try
    {
        GM_TIMEOUT_TIMEOUT = vm["GM_TIMEOUT_TIMEOUT"].as<unsigned int>();
    }
    catch (boost::bad_any_cast& e)
    {
        throw std::runtime_error(
                "GM_TIMEOUT_TIMEOUT is missing, please check your timings config");
    }

    try
    {
        CSRC_DEFAULT_TIMEOUT = vm["CSRC_DEFAULT_TIMEOUT"].as<unsigned int>();
    }
    catch (boost::bad_any_cast& e)
    {
        throw std::runtime_error(
                "CSRC_DEFAULT_TIMEOUT is missing, please check your timings config");
    }

    try
    {
        LB_PHASE_TIME = vm["LB_PHASE_TIME"].as<unsigned int>();
    }
    catch (boost::bad_any_cast& e)
    {
        throw std::runtime_error(
                "LB_PHASE_TIME is missing, please check your timings config");
    }


}

}
}

