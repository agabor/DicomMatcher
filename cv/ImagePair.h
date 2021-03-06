//
// Created by agabor on 2017.09.14..
//

#ifndef CV_TEST_IMAGEPAIR_H
#define CV_TEST_IMAGEPAIR_H


#include <memory>
#include <tuple>

#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>

#include "Image.h"
#include "MatchList.h"

class ImagePair {
public:
    ImagePair(const MatchSettings &settings, std::shared_ptr<Image> a, std::shared_ptr<Image> b);

    size_t matchCount() const;

    cv::Mat matchImage() const;

    std::string label() const;

    std::shared_ptr<Image> image_a;
    std::shared_ptr<Image> image_b;

private:
    void match();

    MatchSettings settings;
    std::vector<cv::KeyPoint> matchedKeyPoints1;
    std::vector<cv::KeyPoint> matchedKeyPoints2;
    std::vector<cv::KeyPoint> matchedScaledKeyPoints1;
    std::vector<cv::KeyPoint> matchedScaledKeyPoints2;
    std::vector<cv::DMatch> aggr_matches;

    void matchOctave(int octave);

    MatchList getMatchList(int octave) const;

    MatchList getScaledMatchList(int octave) const;

    void acceptMatch(int octave, const cv::DMatch &match);

    cv::Mat keyPointImageA() const;

    cv::Mat keyPointImageB() const;

    int homography() const;
};


#endif //CV_TEST_IMAGEPAIR_H
